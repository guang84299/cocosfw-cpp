//
//  GHtttpService.cpp
//  libguang
//
//  Created by ChunGuang Yan on 15/11/13.
//  Copyright (c) 2015年 xindong. All rights reserved.
//

#include "GHtttpService.h"
#include "curl/curl.h"
#include <iostream>

USING_NS_CC;

static GHtttpService* instance = nullptr;

GHtttpService* GHtttpService::getInstance()
{
    if(!instance)
    {
        instance = new GHtttpService();
    }
    return instance;
}

void GHtttpService::destroy()
{
    delete instance;
    instance = nullptr;
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
    
    std::cout << "~GHtttpService()!!!!" << std::endl;
}

void GHtttpService::request(GHttpTask* task)
{
    CURL* handle = this->getHandle(task);
    this->handle_list.push_back(handle);
    this->task_list.push_back(task);
    auto success = curl_easy_perform(handle);
    

    if(success == CURLE_OK)
    {
        std::cout << "request ok!!!!" << std::endl;
    }
    else
    {
        std::cout << "failure!!!!" << std::endl;
    }
    this->removeHandle(handle);
    this->removeTask(task);
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
    GHttpTask* task = static_cast<GHttpTask*>(userp);
    
    char *s1 = task->getData();
    char *s2 = (char *)(buffer);
    
    char *result = (char *)malloc(task->getDataLen() + nmemb);
    if(s1)
     memcpy(result, s1, task->getDataLen());
    memcpy(result + task->getDataLen(), s2, nmemb);
    
    task->setData(result);
    task->setDataLen(task->getDataLen() + nmemb);
    
    std::cout << task->getProgress() << std::endl;
    
    return nmemb;
}

int GHtttpService::progress_callback(void *clientp, double dltotal, double dlnow, double ultotal, double ulnow)
{
    if(dltotal > 0)
    {
        GHttpTask* task = static_cast<GHttpTask*>(clientp);
        task->setProgress(dlnow/dltotal*100);
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

void GHtttpService::removeTask(GHttpTask* task)
{
    for(int i=0; i<this->task_list.size(); i++)
    {
        if(this->task_list[i] == task)
        {
            this->task_list.erase(this->task_list.begin() + i);
            return;
        }
        
    }

}

//------------------------------------------GHttpTask----------------------------------------------------
GHttpTask::GHttpTask() :
type(REQUEST),
progress(0),
speed(0),
timeout(5),
len(0),
data(nullptr)
{
    
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
    this->data = data;
}
char* GHttpTask::getData()
{
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

