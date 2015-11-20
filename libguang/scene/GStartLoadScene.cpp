//
//  GStartLoadScene.cpp
//  libguang
//
//  Created by ChunGuang Yan on 15/11/20.
//  Copyright © 2015年 xindong. All rights reserved.
//

#include "GStartLoadScene.h"

USING_NS_CC;

bool GStartLoadScene::init()
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
    this->scheduleOnce(schedule_selector(GStartLoadScene::decData), 0.3);
    this->schedule(schedule_selector(GStartLoadScene::updateLabel), 0.3);
    
    return true;
}

void GStartLoadScene::decData(float dt)
{
    
}

void GStartLoadScene::updateLabel(float dt)
{
    std::string s = "正在解压文件，请稍后";
    for(int i=0;i<this->_num;i++)
    {
        s += ".";
    }
    this->_num ++;
    this->_num = this->_num >= 4 ? 0 : this->_num;
    this->label_text->setString(s);
    
}
