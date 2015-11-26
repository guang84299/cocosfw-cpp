//
//  GDeviceInfo.h
//  libguang
//
//  Created by ChunGuang Yan on 15/11/26.
//  Copyright © 2015年 guang. All rights reserved.
//

#ifndef GDeviceInfo_h
#define GDeviceInfo_h

#include "cocos2d.h"

class GDeviceInfo
{
public:
    static GDeviceInfo* getInstance();
    
    /**
     * 模式
     */
    virtual bool mode_debug();    // DEBUG版本
    virtual bool mode_release();  // RELEASE版本
    
    /**
     * 内存
     */
    virtual unsigned int memory_all();
    virtual unsigned int memory_used() = 0;
    virtual unsigned int memory_free() = 0;
    
    /**
     * SD卡
     */
    virtual std::string getSDPath() = 0;
    virtual bool isSDEnable() = 0;
    
    /**
     * 系统类型
     */
    virtual bool os_is_wp();
    virtual bool os_is_ios();
    virtual bool os_is_html5();
    virtual bool os_is_android();
    
    /**
     * CPU
     */
    virtual int cpu_core();
    virtual float cpu_usage() = 0;
    
    /**
     * 版本号
     */
    virtual int version_js();
    virtual int version_resource();
    
    
    /**
     * 硬件、运营商
     */
    virtual std::string device_uuid();
    virtual std::string device_telecom()  = 0;
    virtual std::string device_hardware() = 0;
    virtual std::string device_network()  = 0;
    
    /**
     * UUID
     */
    virtual std::string uuid();
    
    /**
     * 打开浏览器
     */
    virtual void open_browser(const std::string &url) = 0;
    
    /**
     * 浏览器属性
     */
    virtual std::string browser_useragent() = 0;
    
    /**
     * 振动
     */
    virtual void vibrate() = 0;
    
    /**
     * 唤醒
     */
    virtual void keep_awake(bool keep) = 0;
    
    /**
     * 键盘
     */
    virtual bool keyboard_exist() = 0;
    virtual void keyboard_close() = 0;
};

#endif /* GDeviceInfo_h */
