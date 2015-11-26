//
//  GDeviceInfoIOS.h
//  libguang
//
//  Created by ChunGuang Yan on 15/11/26.
//  Copyright © 2015年 guang. All rights reserved.
//

#ifndef GDeviceInfoIOS_h
#define GDeviceInfoIOS_h

#include "tools/GDeviceInfo.h"

class GDeviceInfoIOS : public GDeviceInfo
{
public:
    static GDeviceInfoIOS* getInstance();
    
    
    /**
     * 内存
     */
    virtual unsigned int memory_used();
    virtual unsigned int memory_free();
    
    /**
     * SD卡
     */
    virtual std::string getSDPath();
    virtual bool isSDEnable();
    
    /**
     * CPU
     */
    virtual float cpu_usage();
    
    /**
     * 硬件、运营商
     */
    virtual std::string device_telecom();
    virtual std::string device_hardware();
    virtual std::string device_network();
    
    /**
     * 打开浏览器
     */
    virtual void open_browser(const std::string &url);
    
    /**
     * 浏览器属性
     */
    virtual std::string browser_useragent();
    
    /**
     * 振动
     */
    virtual void vibrate();
    
    /**
     * 唤醒
     */
    virtual void keep_awake(bool keep);
    
    /**
     * 键盘
     */
    virtual bool keyboard_exist();
    virtual void keyboard_close();
};

#endif /* GDeviceInfoIOS_h */
