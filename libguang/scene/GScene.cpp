//
//  GScene.cpp
//  libguang
//
//  Created by YanChunGuang on 15/11/25.
//  Copyright © 2015年 guang. All rights reserved.
//

#include "GScene.h"

USING_NS_CC;

bool GScene::init()
{
    auto dir = Director::getInstance();
    bool display = dir->isDisplayStats();
    dir->setDisplayStats(false);
    
    return true;
}