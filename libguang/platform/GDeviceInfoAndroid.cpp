//
//  GDeviceInfoAndroid.cpp
//  libguang
//
//  Created by ChunGuang Yan on 15/11/26.
//  Copyright © 2015年 guang. All rights reserved.
//

#include "GDeviceInfoAndroid.h"

#ifdef ANDROID

#include "platform/android/jni/JniHelper.h"

#include "tools/GLogger.h"

USING_NS_CC;

static GDeviceInfoAndroid* _instanceGDeviceInfoAndroid = nullptr;

GDeviceInfoAndroid* GDeviceInfoAndroid::getInstance()
{
    if(!_instanceGDeviceInfoAndroid)
    {
        _instanceGDeviceInfoAndroid = new GDeviceInfoAndroid();
    }
    return _instanceGDeviceInfoAndroid;
}

unsigned int GDeviceInfoAndroid::memory_used()
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "memory_used",
                                                 "()I"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return 0;
    }
    
    int use = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    return use;
}

unsigned int GDeviceInfoAndroid::memory_free()
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "memory_free",
                                        "()I"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return 0;
    }
    
    int use = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    return use;

}

std::string GDeviceInfoAndroid::getSDPath()
{
    return "/mnt/sdcard/";
}

bool GDeviceInfoAndroid::isSDEnable()
{
    
    // check path exists
    if (!FileUtils::getInstance()->isDirectoryExist(this->getSDPath()))
    {
        bool b = FileUtils::getInstance()->createDirectory(this->getSDPath());
        if(!b)
        return false;
    }
    
    std::string filePath = this->getSDPath() + "test.txt";
    
    // remove a possibly existing test file
    FileUtils::getInstance()->removeFile(filePath.c_str());
    
    // try to write the test file
    bool writable = GResource::write_file(filePath, (unsigned char*)"hello world", 11);
    
    // try to read the test file
    bool readable = GResource::read_file(filePath).getSize() > 0;
    
    // remove test file
    FileUtils::getInstance()->removeFile(filePath.c_str());
    
    return readable && writable;

}

float GDeviceInfoAndroid::cpu_usage()
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "cpu_usage",
                                        "()F"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return 0;
    }
    
    float use = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    return use;
}

std::string GDeviceInfoAndroid::device_telecom()
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "device_telecom",
                                                 "()Ljava/lang/String;"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return "";
    }
    
    jstring retFromJava = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
    const char *str     = methodInfo.env->GetStringUTFChars(retFromJava, 0);
    
    std::string info(str);
    
    methodInfo.env->ReleaseStringUTFChars(retFromJava, str);
    methodInfo.env->DeleteLocalRef(retFromJava);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    return info;
}

std::string GDeviceInfoAndroid::device_hardware()
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "device_hardware",
                                                 "()Ljava/lang/String;"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return "";
    }
    
    jstring retFromJava = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
    const char *str     = methodInfo.env->GetStringUTFChars(retFromJava, 0);
    
    std::string info(str);
    
    methodInfo.env->ReleaseStringUTFChars(retFromJava, str);
    methodInfo.env->DeleteLocalRef(retFromJava);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    return info;

}

std::string GDeviceInfoAndroid::device_network()
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "device_network",
                                                 "()Ljava/lang/String;"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return "";
    }
    
    jstring retFromJava = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
    const char *str     = methodInfo.env->GetStringUTFChars(retFromJava, 0);
    
    std::string info(str);
    
    methodInfo.env->ReleaseStringUTFChars(retFromJava, str);
    methodInfo.env->DeleteLocalRef(retFromJava);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    return info;
}

void GDeviceInfoAndroid::open_browser(const std::string &url)
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "open_browser",
                                                 "(Ljava/lang/String;)V"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return;
    }
    
    jstring jstrInfo = methodInfo.env->NewStringUTF(url.c_str());
    
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jstrInfo);
    
    methodInfo.env->DeleteLocalRef(jstrInfo);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

std::string GDeviceInfoAndroid::browser_useragent()
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "browser_useragent",
                                                 "()Ljava/lang/String;"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return "";
    }
    
    jstring retFromJava = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID);
    const char *str     = methodInfo.env->GetStringUTFChars(retFromJava, 0);
    
    std::string info(str);
    
    methodInfo.env->ReleaseStringUTFChars(retFromJava, str);
    methodInfo.env->DeleteLocalRef(retFromJava);
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return info;
}

void GDeviceInfoAndroid::vibrate()
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "vibrate",
                                        "()V"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return;
    }
    
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

void GDeviceInfoAndroid::keep_awake(bool keep)
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "keep_awake",
                                        "(Z)V"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return;
    }
    
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, keep);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
}

bool GDeviceInfoAndroid::keyboard_exist()
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "keyboard_exist",
                                        "()Z"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return;
    }
    
    jbool exist = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);
    
    return exist;
}

void GDeviceInfoAndroid::keyboard_close()
{
    JniMethodInfo methodInfo;
    if (!JniHelper::getStaticMethodInfo(methodInfo, "com/guang/libguangjni/GDeviceInfoAndroid", "keyboard_close",
                                        "()V"))
    {
        GLogE("%s %d: error to get methodInfo", __FILE__, __LINE__);
        return;
    }
    
    methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
    
    methodInfo.env->DeleteLocalRef(methodInfo.classID);

}


// ------------------------------------------------------------------
// 获取JS、PIShell、Resource的版本号
extern "C"
{
    JNIEXPORT int JNICALL Java_com_guang_libguangjni_GDeviceInfoAndroid_nativeVersionJS(JNIEnv *env, jobject thiz)
    {
        return GDeviceInfo::getInstance()->version_js();
    }
    
    JNIEXPORT int JNICALL Java_com_guang_libguangjni_GDeviceInfoAndroid_nativeVersionResource(JNIEnv *env, jobject thiz)
    {
        return GDeviceInfo::getInstance()->version_resource();
    }
}

#endif