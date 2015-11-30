//
//  GResource.h
//  libguang
//
//  Created by ChunGuang Yan on 15/11/19.
//  Copyright © 2015年 guang. All rights reserved.
//

#ifndef GResource_h
#define GResource_h

#include "cocos2d.h"

class GResource
{
public:
    static GResource* getInstance();
    //可写路径
    std::string getWritePath();
    //代码URL
    std::string getCodeUrl();
    //资源URL
    std::string getResUrl();
    //可写代码路径
    std::string getWriteCodePath();
    //可写资源路径
    std::string getWriteResPath();
    //临时路径
    std::string getTempPath();
    //缓存路径
    std::string getCachePath();
    //根据下载文件创建文件夹
    bool createDirForUrlFile(std::string file,bool isCode);
    //返回一个文件的根目录
    static std::string baseDir(std::string file);
    //返回一个文件的文件名
    static std::string baseFileName(std::string file);
    //判断一个字符串是否为文件
    static bool isFile(std::string path);
    //拷贝一个文件
    static bool copyFile(std::string file, std::string target);
    //删除
    static bool removeFile(std::string file);
    //解压
    static bool decompress(std::string zip, bool isDecryption);
    //解密
    static bool decryption(const char* bytes,int len);
    // 读取、写入磁盘
    static cocos2d::Data read_file(const std::string &path, uint32_t offset = 0, uint32_t length = 0);
    static bool write_file(const std::string &path, const uint8_t *data, uint32_t size);
    static bool append_file(const std::string &path, const uint8_t *data, uint32_t size);
    
private:
    std::string _writePath;
    std::string _codeUrl;
    std::string _resUrl;
    std::string _writeCodePath;
    std::string _writeResPath;
    std::string _tempPath;
    std::string _cachePath;
};

#endif /* GResource_h */
