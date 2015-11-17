//
//  GGameControl.cpp
//  libguang
//
//  Created by guang on 15/11/17.
//  Copyright © 2015年 xindong. All rights reserved.
//

#include "GGameControl.h"
#include "net/GHtttpService.h"

static GGameControl* instance = nullptr;

#define PRELOAD_ROOT_PATH "http://localhost:63342/cocosfw"

GGameControl* GGameControl::getInstance()
{
    if(!instance)
    {
        instance = new GGameControl();
    }
    return instance;
}

void GGameControl::preload()
{
    GHtttpService* http = GHtttpService::getInstance();
    
}

void GGameControl::loadCallback(std::string url, bool success)
{
    
}