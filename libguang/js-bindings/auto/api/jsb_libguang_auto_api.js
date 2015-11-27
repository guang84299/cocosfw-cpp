
/**
 * @class GHtttpService
 */
GHtttpService = {

/**
 * @method download
 * @param {GHttpTask} arg0
 */
download : function (
ghttptask 
)
{
},

/**
 * @method asyncDownload
 * @param {GHttpTask} arg0
 */
asyncDownload : function (
ghttptask 
)
{
},

/**
 * @method request
 * @param {GHttpTask} arg0
 */
request : function (
ghttptask 
)
{
},

/**
 * @method destroy
 */
destroy : function (
)
{
},

/**
 * @method getInstance
 * @return {GHtttpService}
 */
getInstance : function (
)
{
    return GHtttpService;
},

};

/**
 * @class GStartLoadScene
 */
GStartLoadScene = {

/**
 * @method updateLabel
 * @param {float} arg0
 */
updateLabel : function (
float 
)
{
},

/**
 * @method init
 * @return {bool}
 */
init : function (
)
{
    return false;
},

/**
 * @method decData
 * @param {float} arg0
 */
decData : function (
float 
)
{
},

/**
 * @method create
 * @return {GStartLoadScene}
 */
create : function (
)
{
    return GStartLoadScene;
},

};

/**
 * @class GDebugLoadScene
 */
GDebugLoadScene = {

/**
 * @method updateLabel
 * @param {float} arg0
 */
updateLabel : function (
float 
)
{
},

/**
 * @method init
 * @return {bool}
 */
init : function (
)
{
    return false;
},

/**
 * @method loadBase
 * @param {float} arg0
 */
loadBase : function (
float 
)
{
},

/**
 * @method preload
 * @param {String} arg0
 * @return {bool}
 */
preload : function (
str 
)
{
    return false;
},

/**
 * @method loadCallback
 * @param {String} arg0
 * @param {bool} arg1
 */
loadCallback : function (
str, 
bool 
)
{
},

/**
 * @method create
 * @return {GDebugLoadScene}
 */
create : function (
)
{
    return GDebugLoadScene;
},

/**
 * @method preloadCallback
 * @param {String} arg0
 * @param {bool} arg1
 */
preloadCallback : function (
str, 
bool 
)
{
},

};

/**
 * @class GGameControl
 */
GGameControl = {

/**
 * @method init
 * @return {bool}
 */
init : function (
)
{
    return false;
},

/**
 * @method run
 */
run : function (
)
{
},

/**
 * @method includeScript
 * @param {JSContext} arg0
 * @param {unsigned int} arg1
 * @param {JS::Value} arg2
 * @return {bool}
 */
includeScript : function (
jscontext, 
int, 
value 
)
{
    return false;
},

/**
 * @method getInstance
 * @return {GGameControl}
 */
getInstance : function (
)
{
    return GGameControl;
},

};

/**
 * @class GResource
 */
GResource = {

/**
 * @method copyFile
 * @param {String} arg0
 * @param {String} arg1
 * @return {bool}
 */
copyFile : function (
str, 
str 
)
{
    return false;
},

/**
 * @method getCachePath
 * @return {String}
 */
getCachePath : function (
)
{
    return ;
},

/**
 * @method decryption
 * @param {char} arg0
 * @param {int} arg1
 * @return {bool}
 */
decryption : function (
char, 
int 
)
{
    return false;
},

/**
 * @method getWritePath
 * @return {String}
 */
getWritePath : function (
)
{
    return ;
},

/**
 * @method getWriteResPath
 * @return {String}
 */
getWriteResPath : function (
)
{
    return ;
},

/**
 * @method decompress
 * @param {String} arg0
 * @param {bool} arg1
 * @return {bool}
 */
decompress : function (
str, 
bool 
)
{
    return false;
},

/**
 * @method removeFile
 * @param {String} arg0
 * @return {bool}
 */
removeFile : function (
str 
)
{
    return false;
},

/**
 * @method getResUrl
 * @return {String}
 */
getResUrl : function (
)
{
    return ;
},

/**
 * @method getCodeUrl
 * @return {String}
 */
getCodeUrl : function (
)
{
    return ;
},

/**
 * @method baseDir
 * @param {String} arg0
 * @return {String}
 */
baseDir : function (
str 
)
{
    return ;
},

/**
 * @method createDirForUrlFile
 * @param {String} arg0
 * @param {bool} arg1
 * @return {bool}
 */
createDirForUrlFile : function (
str, 
bool 
)
{
    return false;
},

/**
 * @method baseFileName
 * @param {String} arg0
 * @return {String}
 */
baseFileName : function (
str 
)
{
    return ;
},

/**
 * @method getWriteCodePath
 * @return {String}
 */
getWriteCodePath : function (
)
{
    return ;
},

/**
 * @method isFile
 * @param {String} arg0
 * @return {bool}
 */
isFile : function (
str 
)
{
    return false;
},

/**
 * @method getTempPath
 * @return {String}
 */
getTempPath : function (
)
{
    return ;
},

/**
 * @method write_file
 * @param {String} arg0
 * @param {unsigned char} arg1
 * @param {unsigned int} arg2
 * @return {bool}
 */
write_file : function (
str, 
char, 
int 
)
{
    return false;
},

/**
 * @method append_file
 * @param {String} arg0
 * @param {unsigned char} arg1
 * @param {unsigned int} arg2
 * @return {bool}
 */
append_file : function (
str, 
char, 
int 
)
{
    return false;
},

/**
 * @method read_file
 * @param {String} arg0
 * @param {unsigned int} arg1
 * @param {unsigned int} arg2
 * @return {cc.Data}
 */
read_file : function (
str, 
int, 
int 
)
{
    return cc.Data;
},

/**
 * @method getInstance
 * @return {GResource}
 */
getInstance : function (
)
{
    return GResource;
},

};

/**
 * @class GUTF8
 */
GUTF8 = {

};

/**
 * @class GLogger
 */
GLogger = {

/**
 * @method debug
 * @param {String} arg0
 */
debug : function (
str 
)
{
},

/**
 * @method error
 * @param {String} arg0
 */
error : function (
str 
)
{
},

/**
 * @method getInstance
 * @return {GLogger}
 */
getInstance : function (
)
{
    return GLogger;
},

};

/**
 * @class GDeviceInfo
 */
GDeviceInfo = {

/**
 * @method cpu_usage
 * @return {float}
 */
cpu_usage : function (
)
{
    return 0;
},

/**
 * @method device_uuid
 * @return {String}
 */
device_uuid : function (
)
{
    return ;
},

/**
 * @method os_is_android
 * @return {bool}
 */
os_is_android : function (
)
{
    return false;
},

/**
 * @method getSDPath
 * @return {String}
 */
getSDPath : function (
)
{
    return ;
},

/**
 * @method memory_all
 * @return {unsigned int}
 */
memory_all : function (
)
{
    return 0;
},

/**
 * @method version_js
 * @return {int}
 */
version_js : function (
)
{
    return 0;
},

/**
 * @method os_is_ios
 * @return {bool}
 */
os_is_ios : function (
)
{
    return false;
},

/**
 * @method device_network
 * @return {String}
 */
device_network : function (
)
{
    return ;
},

/**
 * @method cpu_core
 * @return {int}
 */
cpu_core : function (
)
{
    return 0;
},

/**
 * @method device_hardware
 * @return {String}
 */
device_hardware : function (
)
{
    return ;
},

/**
 * @method uuid
 * @return {String}
 */
uuid : function (
)
{
    return ;
},

/**
 * @method vibrate
 */
vibrate : function (
)
{
},

/**
 * @method os_is_wp
 * @return {bool}
 */
os_is_wp : function (
)
{
    return false;
},

/**
 * @method isSDEnable
 * @return {bool}
 */
isSDEnable : function (
)
{
    return false;
},

/**
 * @method mode_release
 * @return {bool}
 */
mode_release : function (
)
{
    return false;
},

/**
 * @method memory_used
 * @return {unsigned int}
 */
memory_used : function (
)
{
    return 0;
},

/**
 * @method memory_free
 * @return {unsigned int}
 */
memory_free : function (
)
{
    return 0;
},

/**
 * @method browser_useragent
 * @return {String}
 */
browser_useragent : function (
)
{
    return ;
},

/**
 * @method keyboard_exist
 * @return {bool}
 */
keyboard_exist : function (
)
{
    return false;
},

/**
 * @method device_telecom
 * @return {String}
 */
device_telecom : function (
)
{
    return ;
},

/**
 * @method version_resource
 * @return {int}
 */
version_resource : function (
)
{
    return 0;
},

/**
 * @method open_browser
 * @param {String} arg0
 */
open_browser : function (
str 
)
{
},

/**
 * @method mode_debug
 * @return {bool}
 */
mode_debug : function (
)
{
    return false;
},

/**
 * @method os_is_html5
 * @return {bool}
 */
os_is_html5 : function (
)
{
    return false;
},

/**
 * @method keyboard_close
 */
keyboard_close : function (
)
{
},

/**
 * @method keep_awake
 * @param {bool} arg0
 */
keep_awake : function (
bool 
)
{
},

/**
 * @method getInstance
 * @return {GDeviceInfo}
 */
getInstance : function (
)
{
    return GDeviceInfo;
},

};

/**
 * @class GDeviceInfoAndroid
 */
GDeviceInfoAndroid = {

/**
 * @method memory_used
 * @return {unsigned int}
 */
memory_used : function (
)
{
    return 0;
},

/**
 * @method cpu_usage
 * @return {float}
 */
cpu_usage : function (
)
{
    return 0;
},

/**
 * @method memory_free
 * @return {unsigned int}
 */
memory_free : function (
)
{
    return 0;
},

/**
 * @method keyboard_close
 */
keyboard_close : function (
)
{
},

/**
 * @method browser_useragent
 * @return {String}
 */
browser_useragent : function (
)
{
    return ;
},

/**
 * @method isSDEnable
 * @return {bool}
 */
isSDEnable : function (
)
{
    return false;
},

/**
 * @method vibrate
 */
vibrate : function (
)
{
},

/**
 * @method getSDPath
 * @return {String}
 */
getSDPath : function (
)
{
    return ;
},

/**
 * @method device_telecom
 * @return {String}
 */
device_telecom : function (
)
{
    return ;
},

/**
 * @method device_network
 * @return {String}
 */
device_network : function (
)
{
    return ;
},

/**
 * @method keep_awake
 * @param {bool} arg0
 */
keep_awake : function (
bool 
)
{
},

/**
 * @method open_browser
 * @param {String} arg0
 */
open_browser : function (
str 
)
{
},

/**
 * @method device_hardware
 * @return {String}
 */
device_hardware : function (
)
{
    return ;
},

/**
 * @method keyboard_exist
 * @return {bool}
 */
keyboard_exist : function (
)
{
    return false;
},

/**
 * @method getInstance
 * @return {GDeviceInfoAndroid}
 */
getInstance : function (
)
{
    return GDeviceInfoAndroid;
},

};
