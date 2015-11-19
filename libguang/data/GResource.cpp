//
//  GResource.cpp
//  libguang
//
//  Created by ChunGuang Yan on 15/11/19.
//  Copyright © 2015年 xindong. All rights reserved.
//

#include "GResource.h"

USING_NS_CC;

#define G_CODE_URL "http://localhost:63342/cocosfw/"

static GResource* _instanceGResource = nullptr;

GResource* GResource::getInstance()
{
    if(!_instanceGResource)
    {
        _instanceGResource = new GResource();
    }
    return _instanceGResource;
}

std::string GResource::getWritePath()
{
    if(this->_writePath.empty())
    {
        this->_writePath = FileUtils::getInstance()->getWritablePath() + "cocosfw/";
    }
    return this->_writePath;
}

std::string GResource::getCodeUrl()
{
    if(this->_codeUrl.empty())
    {
        this->_codeUrl = G_CODE_URL;
    }
    return this->_codeUrl;
}

std::string GResource::getResUrl()
{
    if(this->_resUrl.empty())
    {
        this->_resUrl = G_CODE_URL;
    }
    return this->_resUrl;
}

std::string GResource::getWriteCodePath()
{
    if(this->_writeCodePath.empty())
    {
        this->_writeCodePath = FileUtils::getInstance()->getWritablePath() + "cocosfw/src/";
    }
    return this->_writeCodePath;
}

std::string GResource::getWriteResPath()
{
    if(this->_writeResPath.empty())
    {
        this->_writeResPath = FileUtils::getInstance()->getWritablePath() + "cocosfw/res/";
    }
    return this->_writeResPath;
}

std::string GResource::getTempPath()
{
    if(this->_tempPath.empty())
    {
        this->_tempPath = FileUtils::getInstance()->getWritablePath() + "cocosfw/temp/";
    }
    return this->_tempPath;
}

std::string GResource::getCachePath()
{
    if(this->_cachePath.empty())
    {
        this->_cachePath = FileUtils::getInstance()->getWritablePath() + "cocosfw/cache/";
    }
    return this->_cachePath;
}

bool GResource::createDirForUrlFile(std::string file, bool isCode)
{
    std::string dir(file);
    std::string path = this->getWriteCodePath();
    if(!isCode)
    {
        path = this->getWriteResPath();
    }
    
    dir = path + dir.substr(0, dir.rfind('/')+1);
    if(!FileUtils::getInstance()->isDirectoryExist(dir))
    {
       return FileUtils::getInstance()->createDirectory(dir);
    }
    return false;
}