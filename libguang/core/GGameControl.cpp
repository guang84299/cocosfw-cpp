//
//  GGameControl.cpp
//  libguang
//
//  Created by guang on 15/11/17.
//  Copyright © 2015年 guang. All rights reserved.
//

#include "GGameControl.h"
#include "scene/GDebugLoadScene.h"
#include "scene/GStartLoadScene.h"
#include "data/GResource.h"


USING_NS_CC;

static GGameControl* _instanceGGameControl = nullptr;


void registerCustomFunc(JSContext* cx, JS::HandleObject global) {
        // register some custom global functions
    JS_DefineFunction(cx, global, "include", GGameControl::includeScript, 1, JSPROP_READONLY | JSPROP_PERMANENT);
}

GGameControl* GGameControl::getInstance()
{
    if(!_instanceGGameControl)
    {
        _instanceGGameControl = new GGameControl();
        _instanceGGameControl->init();
    }
    return _instanceGGameControl;
}

bool GGameControl::init()
{
    
    ScriptingCore::getInstance()->addRegisterCallback(registerCustomFunc);
    
    
    //设置js读写路径
    FileUtils::getInstance()->createDirectory(GResource::getInstance()->getWriteCodePath());
    FileUtils::getInstance()->addSearchPath(GResource::getInstance()->getWriteCodePath());
    //项目读写根路径
    FileUtils::getInstance()->addSearchPath(GResource::getInstance()->getWritePath());
    
    return true;
}

void GGameControl::run()
{
#if COCOS2D_DEBUG
    Director::getInstance()->runWithScene(GDebugLoadScene::create());
#else 
    Director::getInstance()->runWithScene(GStartLoadScene::create());
#endif
}

bool GGameControl::includeScript(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc >= 1)
    {
        JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
        
        // 文件名称
        std::string file(JSStringWrapper(args.get(0).toString()).get());
        
        // 文件前缀
        if (!file.empty() && (file[0] == '/'))
        {
            file.erase(file.begin());
        }
#if COCOS2D_DEBUG
        if(GDebugLoadScene::preload(file))
        {
            return ScriptingCore::executeScript(cx, argc, vp);
        }
#else
        return ScriptingCore::executeScript(cx, argc, vp);
#endif
       
    }
    
    return false;
}