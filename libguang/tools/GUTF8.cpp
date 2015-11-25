//
//  GUTF8.cpp
//  libguang
//
//  Created by ChunGuang Yan on 15/11/19.
//  Copyright © 2015年 guang. All rights reserved.
//

#include "GUTF8.h"

std::string GUTF8::format(const char *fmt, ...)
{
    va_list v1, v2;
    
    va_start(v1, fmt);
    va_copy(v2, v1);
    
    auto tmp = ::vsnprintf(nullptr, 0, fmt, v1) + 1;
    
    if (tmp <= 0)
        return "";
    
    auto len = static_cast<std::size_t>(tmp);
    auto buf = new char[len];
    
    ::vsnprintf(buf, len, fmt, v2);
    std::string ret(buf);
    
    delete[] buf;
    
    va_end(v1);
    va_end(v2);
    
    return ret;
}