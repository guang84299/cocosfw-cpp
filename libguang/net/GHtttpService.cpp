//
//  GHtttpService.cpp
//  libguang
//
//  Created by ChunGuang Yan on 15/11/13.
//  Copyright (c) 2015年 xindong. All rights reserved.
//

#include "GHtttpService.h"
#include "curl/curl.h"
#include "tools/GLogger.h"
#include <thread>

USING_NS_CC;

static GHtttpService* _instanceGHtttpService = nullptr;
static std::mutex mutex;

GHtttpService* GHtttpService::getInstance()
{
    if(!_instanceGHtttpService)
    {
        _instanceGHtttpService = new GHtttpService();
    }
    return _instanceGHtttpService;
}

void GHtttpService::destroy()
{
    delete _instanceGHtttpService;
    _instanceGHtttpService = nullptr;
}

GHtttpService::GHtttpService()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

GHtttpService::~GHtttpService()
{
    for(int i=0; i<this->handle_list.size(); i++)
    {
        curl_easy_cleanup(this->handle_list[i]);
    }
    this->handle_list.clear();
    curl_global_cleanup();
    
    GLog("~GHtttpService!!!");
}

void GHtttpService::request(GHttpTask* task)
{
    CURL* handle = this->getHandle(task);
    
    mutex.lock();
    this->handle_list.push_back(handle);
    mutex.unlock();
    
    auto success = curl_easy_perform(handle);
    
    mutex.lock();
    long retcode = 0;
    curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE , &retcode);

    if(success == CURLE_OK && retcode == 200)
    {
        task->setStatus(true);
        GLog("http request:%s ok",task->getUrl().c_str());
    }
    else
    {
        GLogE("http request:%s failure",task->getUrl().c_str());
    }
    if(task->getType() == GHTTPTYPE::DOWNLOAD)
    {
        task->closeFile();
        if(task->getAsync())//只有异步时才release
            task->release();
    }
    this->removeHandle(handle);
    mutex.unlock();
    
    if(task->callback)
    {
        task->callback(task->getUrl(),task->getStatus());
    }
}

void GHtttpService::download(GHttpTask* task)
{
    task->openFile();
    this->request(task);
}

void GHtttpService::asyncDownload(GHttpTask* task)
{
    task->setAsync(true);
    std::thread t(&GHtttpService::download,this,task);
    t.detach();
}

CURL* GHtttpService::getHandle(GHttpTask* task)
{
    CURL* handle = curl_easy_init();
    
    curl_easy_setopt(handle, CURLOPT_URL, task->getUrl().c_str());
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION,this->write_data);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, task);
    curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 0);
    curl_easy_setopt(handle, CURLOPT_PROGRESSFUNCTION, this->progress_callback);
    curl_easy_setopt(handle, CURLOPT_PROGRESSDATA, task);
    curl_easy_setopt(handle, CURLOPT_TIMEOUT, task->getTimeOut());

    return handle;
}

size_t GHtttpService::write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
    size_t len = size * nmemb;
    if(len == 0)
        return 0;
    GHttpTask* task = static_cast<GHttpTask*>(userp);
    task->write_data(buffer, size, nmemb);
    
    return len;
}

int GHtttpService::progress_callback(void *clientp, double dltotal, double dlnow, double ultotal, double ulnow)
{
    if(dltotal > 0)
    {
        GHttpTask* task = static_cast<GHttpTask*>(clientp);
        task->progress_callback(dltotal, dlnow);
    }
    
    return 0;
}

void GHtttpService::removeHandle(CURL* handle)
{
    for(int i=0; i<this->handle_list.size(); i++)
    {
        if(this->handle_list[i] == handle)
        {
            curl_easy_cleanup(this->handle_list[i]);
             this->handle_list.erase(this->handle_list.begin() + i);
            return;
        }
        
    }
}


//------------------------------------------GHttpTask----------------------------------------------------
GHttpTask::GHttpTask() :
type(GHTTPTYPE::REQUEST),
progress(0),
speed(0),
timeout(0),
len(0),
data(nullptr),
status(false),
async(false),
file(nullptr)
{
}

GHttpTask::~GHttpTask()
{
   // GLog(("----~GHttpTask-----" + this->path).c_str());
}
GHttpTask* GHttpTask::create()
{
    GHttpTask *task = new GHttpTask();
    task->autorelease();
    
    return task;
}

void GHttpTask::write_data(void *buffer, size_t size, size_t nmemb)
{
    size_t len = size * nmemb;
    if(this->getType() == GHTTPTYPE::REQUEST)
    {
        char *s1 = this->getData();
        char *s2 = (char *)(buffer);
        
        char *result = (char *)malloc(this->getDataLen() + len);
        if(s1)
        {
            memcpy(result, s1, this->getDataLen());
        }
        memcpy(result + this->getDataLen(), s2, len);
        
        this->setData(result);
        this->setDataLen(this->getDataLen() + len);
    }
    else
    {
        this->writeFileData((unsigned char *)(buffer), len);
    }
    this->setSpeed(len);
}
void GHttpTask::progress_callback(double dltotal, double dlnow)
{
    this->setProgress(dlnow/dltotal*100);
}

void GHttpTask::setUrl(std::string url)
{
    this->url = url;
}
std::string GHttpTask::getUrl()
{
    return this->url;
}

void GHttpTask::setType(GHTTPTYPE type)
{
    this->type = type;
}
GHTTPTYPE GHttpTask::getType()
{
    return this->type;
}

void GHttpTask::setData(char *data)
{
    if(this->data)
        free(this->data);
    this->data = data;
}
char* GHttpTask::getData()
{
    if(this->type == GHTTPTYPE::DOWNLOAD)
    {
        return nullptr;
    }
    return this->data;
}

void GHttpTask::setDataLen(unsigned long len)
{
    this->len = len;
}
unsigned long GHttpTask::getDataLen()
{
    return this->len;
}

void GHttpTask::setProgress(float progress)
{
    this->progress = progress;
}
float GHttpTask::getProgress()
{
    return this->progress;
}

void GHttpTask::setSpeed(float speed)
{
    this->speed = speed;
}
float GHttpTask::getSpeed()
{
    return this->speed;
}

void GHttpTask::setTimeOut(int time)
{
    this->timeout = time;
}
int GHttpTask::getTimeOut()
{
    return this->timeout;
}

void GHttpTask::setPath(std::string path)
{
    this->path = path;
}
std::string GHttpTask::getPath()
{
    return this->path;
}

void GHttpTask::setStatus(bool status)
{
    this->status = status;
}
bool GHttpTask::getStatus()
{
    return this->status;
}

bool GHttpTask::writeFileData(unsigned char* data,size_t size)
{
    if(!this->file)
    {
         return false;
    }
    else
    {
        fwrite(data, size, 1, this->file);
        return  true;
    }
    
}
FILE * GHttpTask::getFile()
{
    return this->file;
}
void GHttpTask::openFile()
{
    if(!this->file)
    {
        const char* mode = "wb";
        
        auto fileutils = FileUtils::getInstance();
        do
        {
            // Read the file from hardware
            this->file = fopen(fileutils->getSuitableFOpen(this->path).c_str(), mode);
            CC_BREAK_IF(!this->file);
        } while (0);
        
    }
}
void GHttpTask::closeFile()
{
    if(this->file)
    {
        fclose(this->file);
    }
}

void GHttpTask::setCallback(GHttpCallback callback)
{
    this->callback = callback;
}

void GHttpTask::setAsync(bool async)
{
    this->async = async;
}
bool GHttpTask::getAsync()
{
    return this->async;
}
