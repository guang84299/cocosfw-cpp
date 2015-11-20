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

std::string GDebugLoadScene::file_url = "";

bool GDebugLoadScene::init()
{
    auto size = Director::getInstance()->getWinSize();
    auto layer = LayerColor::create(Color4B(255,255,255,255),size.width,size.height);
    this->addChild(layer);
    
    this->label_text = Label::createWithSystemFont("", "", 24);
    this->label_text->setTextColor(Color4B::BLACK);
    this->label_text->setPosition(size.width/3,size.height*0.6);
    this->label_text->setAnchorPoint(Vec2(0,0.5));
    this->addChild(this->label_text);
    
    this->label_file = Label::createWithSystemFont("", "", 20);
    this->label_file->setTextColor(Color4B::BLACK);
    this->label_file->setPosition(size.width/2,size.height*0.4);
    this->addChild( this->label_file);

    this->_num = 0;
    this->scheduleOnce(schedule_selector(GDebugLoadScene::loadBase), 0.3);
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
    std::string s = "正在加载js文件，请稍后";
    for(int i=0;i<this->_num;i++)
    {
        s += ".";
    }
    this->_num ++;
    this->_num = this->_num >= 4 ? 0 : this->_num;
    this->label_text->setString(s);
    
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
