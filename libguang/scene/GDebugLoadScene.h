//
//  GDebugLoadScene.h
//  libguang
//
//  Created by ChunGuang Yan on 15/11/19.
//  Copyright © 2015年 guang. All rights reserved.
//

#ifndef GDebugLoadScene_h
#define GDebugLoadScene_h

#include "cocos2d.h"

class GDebugLoadScene : public cocos2d::Scene
{
public:
    bool init();
    void loadBase(float);
    void updateLabel(float);
    CREATE_FUNC(GDebugLoadScene);
    
    //预加载资源
    static bool preload(std::string file);
    static void loadCallback(std::string url,bool success);
    static void preloadCallback(std::string url,bool success);
    
    static std::string file_url;
private:
    int _num;
    cocos2d::Label *label_text;
    cocos2d::Label *label_file;
    
};

#endif /* GDebugLoadScene_h */
