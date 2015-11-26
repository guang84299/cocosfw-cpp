//
//  guang.h
//  libguang
//
//  Created by ChunGuang Yan on 15/11/13.
//  Copyright (c) 2015年 guang. All rights reserved.
//

#ifndef __libguang__guang__
#define __libguang__guang__

#include <stdio.h>

#include "net/GHtttpService.h"

#include "scene/GScene.h"
#include "scene/GStartLoadScene.h"
#include "scene/GDebugLoadScene.h"

#include "core/GGameControl.h"

#include "data/GResource.h"

#include "tools/GUTF8.h"
#include "tools/GLogger.h"
#include "tools/GDeviceInfo.h"

#ifdef ANDROID
#include "platform/GDeviceInfoAndroid.h"
#else
#include "platform/GDeviceInfoIOS.h"
#endif

#endif /* defined(__libguang__guang__) */
