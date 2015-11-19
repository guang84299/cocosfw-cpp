//
//  GGameControl.h
//  libguang
//
//  Created by ChunGuang Yan on 15/11/17.
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
};

#endif /* GGameControl_h */
