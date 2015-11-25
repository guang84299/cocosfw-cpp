//
//  GStartLoadScene.h
//  libguang
//
//  Created by ChunGuang Yan on 15/11/20.
//  Copyright © 2015年 guang. All rights reserved.
//

#ifndef GStartLoadScene_h
#define GStartLoadScene_h

#include "cocos2d.h"

class GStartLoadScene : public cocos2d::Scene
{
public:
    bool init();
    
    CREATE_FUNC(GStartLoadScene);
    
    //解压数据
    void decData(float);
    void updateLabel(float);
    
private:
    int _num;
    cocos2d::Label *label_text;
    cocos2d::Label *label_file;
    
};


#endif /* GStartLoadScene_h */
