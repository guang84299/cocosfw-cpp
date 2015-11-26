//
//  GDeviceInfo.cpp
//  libguang
//
//  Created by ChunGuang Yan on 15/11/26.
//  Copyright © 2015年 guang. All rights reserved.
//

#include "GDeviceInfo.h"

#ifdef ANDROID
#include "platform/GDeviceInfoAndroid.h"
#else
#include "platform/GDeviceInfoIOS.h"
#endif

USING_NS_CC;


GDeviceInfo* GDeviceInfo::getInstance()
{
#ifdef ANDROID
    return GDeviceInfoAndroid::getInstance();
#else
    return GDeviceInfoIOS::getInstance();
#endif
}

#pragma mark Memory

unsigned int GDeviceInfo::memory_all()
{
    return this->memory_used() + this->memory_free();
}

#pragma mark Mode

bool GDeviceInfo::mode_debug()
{
#if COCOS2D_DEBUG
    return true;
#else
    return false;
#endif
}

bool GDeviceInfo::mode_release()
{
    return !this->mode_debug();
}


#pragma mark OS

bool GDeviceInfo::os_is_wp()
{
    return false;
}

bool GDeviceInfo::os_is_ios()
{
#ifdef ANDROID
    return false;
#else
    return true;
#endif
}

bool GDeviceInfo::os_is_html5()
{
    return false;
}

bool GDeviceInfo::os_is_android()
{
#ifdef ANDROID
    return true;
#else
    return false;
#endif
}

#pragma mark CPU

int GDeviceInfo::cpu_core()
{
    return std::thread::hardware_concurrency();
}

#pragma mark Version

int GDeviceInfo::version_js()
{
    return 0;
}

int GDeviceInfo::version_resource()
{
    
    return 0;
}

std::string GDeviceInfo::device_uuid()
{
    auto unique = UserDefault::getInstance()->getStringForKey("unique_id", "");
    
    if (unique.empty())
    {
        unique = this->uuid();
        UserDefault::getInstance()->setStringForKey("unique_id", unique);
    }
    
    return unique;
}

std::string GDeviceInfo::uuid()
{
    std::string unique("xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx");
    
    std::stringstream ss;
    std::random_device rd;
    
    for (auto i = 0; i < unique.size(); ++i)
    {
        auto c = unique[i];
        if ((c != 'x') && (c != 'y'))
            continue;
        
        auto r = (int)(((float)rd() / std::random_device::max()) * 16) | 0;
        auto v = c == 'x' ? r : ((r & 0x3) | 0x8);
        
        ss.str("");
        ss << std::hex << std::uppercase << v;
        
        unique[i] = ss.str()[0];
    }
    
    return unique;
}