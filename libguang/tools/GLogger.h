//
//  GLogger.h
//  libguang
//
//  Created by ChunGuang Yan on 15/11/19.
//  Copyright © 2015年 guang. All rights reserved.
//

#ifndef GLogger_h
#define GLogger_h

#include "cocos2d.h"
#include "tools/GUTF8.h"

#if COCOS2D_DEBUG
    #define GLog(fmt,...) GLogger::getInstance()->debug(GUTF8::format(fmt, ##__VA_ARGS__))
#else
    #define GLog(...) do {} while(false)
#endif
#define GLogE(fmt,...) GLogger::getInstance()->error(GUTF8::format(fmt, ##__VA_ARGS__))


class GLogger
{
public:
    static GLogger* getInstance();
    void debug(std::string fmt);
    void error(std::string fmt);
private:
    bool isError;
    void _log(std::string fmt);
};

#endif /* GLogger_h */
