//
//  GGameControl.cpp
//  libguang
//
//  Created by guang on 15/11/17.
//  Copyright © 2015年 xindong. All rights reserved.
//

#include "GGameControl.h"
#include "net/GHtttpService.h"
#include <regex>


USING_NS_CC;

static GGameControl* _instanceGGameControl = nullptr;

#define PRELOAD_ROOT_PATH "http://localhost:63342/cocosfw/"
#define SCRIPT_PATH "cocosfw/src/"
#define PRO_ROOT_PATH "cocosfw/"

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
    std::string path = FileUtils::getInstance()->getWritablePath() + SCRIPT_PATH;
    FileUtils::getInstance()->createDirectory(path);
    FileUtils::getInstance()->addSearchPath(path);
    //项目读写根路径
    path = FileUtils::getInstance()->getWritablePath() + PRO_ROOT_PATH;
    FileUtils::getInstance()->addSearchPath(path);
    
    return true;
}

void GGameControl::run()
{
    GHtttpService* http = GHtttpService::getInstance();
    
    std::string path = FileUtils::getInstance()->getWritablePath() + PRO_ROOT_PATH;
    std::string file = "project.json";
    
    GHttpTask *task = GHttpTask::create();
    task->setUrl(PRELOAD_ROOT_PATH + file);
    task->setType(GHTTPTYPE::DOWNLOAD);
    task->setPath(path + file);
    http->download(task);
    
    task = GHttpTask::create();
    file = "includeFile.js";
    task->setUrl(PRELOAD_ROOT_PATH + file);
    task->setType(GHTTPTYPE::DOWNLOAD);
    task->setPath(path + file);
    task->setCallback(this->loadCallback);
    http->download(task);
}

void GGameControl::loadCallback(std::string url, bool success)
{
    auto sc = ScriptingCore::getInstance();
    sc->start();
    sc->runScript("script/jsb_boot.js");
#if defined(COCOS2D_DEBUG) && (COCOS2D_DEBUG > 0)
    sc->enableDebugger();
#endif
    
    ScriptEngineProtocol *engine = ScriptingCore::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    ScriptingCore::getInstance()->runScript("includeFile.js");
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
        if(GGameControl::preload(file))
        {
            return ScriptingCore::executeScript(cx, argc, vp);
        }
       
    }
    
    return false;
}

bool GGameControl::preload(std::string file)
{
    GHtttpService* http = GHtttpService::getInstance();
    
    std::string path = FileUtils::getInstance()->getWritablePath() + SCRIPT_PATH;
    
    std::string dir(file);
    dir = path + dir.substr(0, dir.rfind('/')+1);
    if(!FileUtils::getInstance()->isDirectoryExist(dir))
    {
        FileUtils::getInstance()->createDirectory(dir);
    }
    
    GHttpTask *task = GHttpTask::create();
    task->setUrl(PRELOAD_ROOT_PATH + file);
    task->setType(GHTTPTYPE::DOWNLOAD);
    task->setPath(path + file);
    
    http->download(task);
    
    return task->getStatus();
}
