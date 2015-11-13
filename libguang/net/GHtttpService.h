//
//  GHtttpService.h
//  libguang
//
//  Created by ChunGuang Yan on 15/11/13.
//  Copyright (c) 2015年 xindong. All rights reserved.
//

#ifndef __libguang__GHtttpService__
#define __libguang__GHtttpService__

#include "cocos2d.h"

class GHtttpService
{
public:
    static GHtttpService* getInstance();
    
protected:
    GHtttpService();
    ~GHtttpService();
    
public:
    void request();
};

#endif /* defined(__libguang__GHtttpService__) */
