//
//  GHtttpService.h
//  libguang
//
//  Created by ChunGuang Yan on 15/11/13.
//  Copyright (c) 2015年 xindong. All rights reserved.
//

#ifndef __libguang__GHtttpService__
#define __libguang__GHtttpService__

#include "cocos2d.h"

class GHttpTask;
class GHtttpService
{
    
#ifndef CURL
    typedef void CURL;
#endif
    
public:
    static GHtttpService* getInstance();
    static void destroy();
    
protected:
    GHtttpService();
    ~GHtttpService();
    
public:
    //http 请求
    void request(GHttpTask* task);
    //单个文件下载
    void download(GHttpTask* task);
    //异步下载
    void asyncDownload(GHttpTask* task);
    
private:
    CURL* getHandle(GHttpTask* task);
    
private:
    std::vector<GHttpTask*> task_list;
    std::vector<CURL*> handle_list;
    void removeHandle(CURL* handle);
    void removeTask(GHttpTask* task);
    static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);
    static int progress_callback(void *clientp, double dltotal, double dlnow, double ultotal, double ulnow);
};

enum GHTTPTYPE {REQUEST,DOWNLOAD};

class GHttpTask
{
public:
    GHttpTask();
    
    void setUrl(std::string url);
    std::string getUrl();
    
    void setType(GHTTPTYPE type);
    GHTTPTYPE getType();
    
    void setData(char *data);
    char* getData();
    
    void setDataLen(unsigned long len);
    unsigned long getDataLen();
    
    void setProgress(float progress);
    float getProgress();
    
    void setSpeed(float speed);
    float getSpeed();
    //秒
    void setTimeOut(int time);
    int getTimeOut();
    //下载文件保存路径
    void setPath(std::string path);
    std::string getPath();
    //文件
    bool writeFileData(unsigned char* data,size_t size);
    FILE * getFile();
    void openFile();
    void closeFile();
    //网络请求状态 true 请求成功
    void setStatus(bool status);
    bool getStatus();
private:
    std::string url;
    GHTTPTYPE type;
    float progress;
    float speed;
    int timeout;
    char* data;
    unsigned long len;
    std::string path;
    bool status;
    FILE *file;
};

#endif /* defined(__libguang__GHtttpService__) */
