//
//  GDebugLoadScene.cpp
//  libguang
//
//  Created by ChunGuang Yan on 15/11/19.
//  Copyright © 2015年 xindong. All rights reserved.
//

#include "GDebugLoadScene.h"
#include "net/GHtttpService.h"
#include "data/GResource.h"
#include "ScriptingCore.h"

USING_NS_CC;

std::string GDebugLoadScene::file_url = nullptr;

bool GDebugLoadScene::init()
{
    auto size = Director::getInstance()->getWinSize();
    auto layer = LayerColor::create(Color4B(255,255,255,255),size.width,size.height);
    this->addChild(layer);
    
    auto label = Label::createWithSystemFont("加载js文件...", "", 24);
    label->setPosition(20,size.height*0.6);
    label->setAnchorPoint(Vec2(0,0.5));
    this->addChild(label);
    
    this->label_file = Label::createWithSystemFont("", "", 20);
    this->label_file->setPosition(size.width/2,size.height*0.4);
    this->addChild( this->label_file);

    this->scheduleOnce(schedule_selector(GDebugLoadScene::loadBase), 0.2);
    this->schedule(schedule_selector(GDebugLoadScene::updateLabel), 0.3);
    
    return true;
}

void GDebugLoadScene::loadBase(float dt)
{
    GHtttpService* http = GHtttpService::getInstance();
    
    std::string path = GResource::getInstance()->getWritePath();
    std::string file = "project.json";
    
    GHttpTask *task = GHttpTask::create();
    task->setUrl(GResource::getInstance()->getCodeUrl() + file);
    task->setType(GHTTPTYPE::DOWNLOAD);
    task->setPath(path + file);
    http->download(task);
    
    task = GHttpTask::create();
    file = "includeFile.js";
    task->setUrl(GResource::getInstance()->getCodeUrl() + file);
    task->setType(GHTTPTYPE::DOWNLOAD);
    task->setPath(path + file);
    task->setCallback(this->loadCallback);
    http->download(task);

}

void GDebugLoadScene::updateLabel(float dt)
{
    this->label_file->setString(GDebugLoadScene::file_url);
    
    if( GDebugLoadScene::file_url == "load end")
    {
        this->unscheduleAllCallbacks();
    }
}

void GDebugLoadScene::loadCallback(std::string url, bool success)
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

void GDebugLoadScene::preloadCallback(std::string url, bool success)
{
    GDebugLoadScene::file_url = "load end";
}

bool GDebugLoadScene::preload(std::string file)
{
    GHtttpService* http = GHtttpService::getInstance();
    
    std::string path = GResource::getInstance()->getWriteCodePath();
    
    GResource::getInstance()->createDirForUrlFile(file, true);
    
    GHttpTask *task = GHttpTask::create();
    task->setUrl(GResource::getInstance()->getCodeUrl() + file);
    task->setType(GHTTPTYPE::DOWNLOAD);
    task->setPath(path + file);
    
    GDebugLoadScene::file_url = task->getUrl();
    if(file == std::string("main.js"))
    {
        task->setCallback(GDebugLoadScene::preloadCallback);
    }
    
    http->download(task);
    
    return task->getStatus();
}
