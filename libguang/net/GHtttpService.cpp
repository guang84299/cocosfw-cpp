//
//  GHtttpService.cpp
//  libguang
//
//  Created by ChunGuang Yan on 15/11/13.
//  Copyright (c) 2015年 xindong. All rights reserved.
//

#include "GHtttpService.h"
#include "curl/curl.h"

static GHtttpService* instance = nullptr;

GHtttpService* GHtttpService::getInstance()
{
    if(!instance)
    {
        instance = new GHtttpService();
    }
    return instance;
}

GHtttpService::GHtttpService()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

GHtttpService::~GHtttpService()
{
    
}