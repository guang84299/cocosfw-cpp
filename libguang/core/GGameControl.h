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

class GGameControl
{
public:
    static GGameControl* getInstance();
    //预加载资源
    void preload();
    void loadCallback(std::string url,bool success);
};

#endif /* GGameControl_h */
