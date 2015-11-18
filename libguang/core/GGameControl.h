//
//  GGameControl.h
//  libguang
//
//  Created by guang on 15/11/17.
//  Copyright © 2015年 xindong. All rights reserved.
//

#ifndef GGameControl_h
#define GGameControl_h

#include "cocos2d.h"
#include "ScriptingCore.h"

class GGameControl 
{
public:
    static GGameControl* getInstance();
    static bool includeScript(JSContext *cx, uint32_t argc, jsval *vp);
    
    bool init();
    void run();
    //预加载资源
    static bool preload(std::string file);
    void loadCallback(std::string url,bool success);
};

#endif /* GGameControl_h */
