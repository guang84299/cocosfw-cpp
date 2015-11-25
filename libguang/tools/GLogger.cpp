//
//  GLogger.cpp
//  libguang
//
//  Created by ChunGuang Yan on 15/11/19.
//  Copyright © 2015年 guang. All rights reserved.
//

#include "GLogger.h"

using namespace cocos2d;

static GLogger* _instanceGLogger = nullptr;

GLogger* GLogger::getInstance()
{
    if(!_instanceGLogger)
    {
        _instanceGLogger = new GLogger();
    }
    return _instanceGLogger;
}

void GLogger::debug(std::string fmt)
{
    this->isError = false;
    fmt = "[DEBUG] " + fmt;
    this->_log(fmt);
}

void GLogger::error(std::string fmt)
{
    this->isError = true;
    fmt = "[ERROR] " + fmt;
    this->_log(fmt);
}

void GLogger::_log(std::string fmt)
{
    char * buf = (char*)fmt.c_str();
    strcat(buf, "\n");
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    if(this->isError)
        __android_log_print(ANDROID_LOG_DEBUG, "cocos2d-x debug info", "%s", buf);
    else
        __android_log_print(ANDROID_LOG_ERROR, "cocos2d-x error info", "%s", buf);
    
#elif CC_TARGET_PLATFORM ==  CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
    
    int pos = 0;
    int len = strlen(buf);
    char tempBuf[MAX_LOG_LENGTH + 1] = { 0 };
    WCHAR wszBuf[MAX_LOG_LENGTH + 1] = { 0 };
    
    do
    {
        std::copy(buf + pos, buf + pos + MAX_LOG_LENGTH, tempBuf);
        
        tempBuf[MAX_LOG_LENGTH] = 0;
        
        MultiByteToWideChar(CP_UTF8, 0, tempBuf, -1, wszBuf, sizeof(wszBuf));
        OutputDebugStringW(wszBuf);
        WideCharToMultiByte(CP_ACP, 0, wszBuf, -1, tempBuf, sizeof(tempBuf), nullptr, FALSE);
        printf("%s", tempBuf);
        
        pos += MAX_LOG_LENGTH;
        
    } while (pos < len);
    SendLogToWindow(buf);
    fflush(stdout);
#else
    // Linux, Mac, iOS, etc
    fprintf(stdout, "%s", buf);
    fflush(stdout);
#endif
    
    Director::getInstance()->getConsole()->log(buf);
}