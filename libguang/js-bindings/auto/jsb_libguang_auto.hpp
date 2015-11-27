#include "base/ccConfig.h"
#ifndef ___h__
#define ___h__

#include "jsapi.h"
#include "jsfriendapi.h"

extern JSClass  *jsb_GHtttpService_class;
extern JSObject *jsb_GHtttpService_prototype;

bool js__GHtttpService_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js__GHtttpService_finalize(JSContext *cx, JSObject *obj);
void js_register__GHtttpService(JSContext *cx, JS::HandleObject global);
void register_all_(JSContext* cx, JS::HandleObject obj);
bool js__GHtttpService_download(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GHtttpService_asyncDownload(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GHtttpService_request(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GHtttpService_destroy(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GHtttpService_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GStartLoadScene_class;
extern JSObject *jsb_GStartLoadScene_prototype;

bool js__GStartLoadScene_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js__GStartLoadScene_finalize(JSContext *cx, JSObject *obj);
void js_register__GStartLoadScene(JSContext *cx, JS::HandleObject global);
void register_all_(JSContext* cx, JS::HandleObject obj);
bool js__GStartLoadScene_updateLabel(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GStartLoadScene_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GStartLoadScene_decData(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GStartLoadScene_create(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GDebugLoadScene_class;
extern JSObject *jsb_GDebugLoadScene_prototype;

bool js__GDebugLoadScene_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js__GDebugLoadScene_finalize(JSContext *cx, JSObject *obj);
void js_register__GDebugLoadScene(JSContext *cx, JS::HandleObject global);
void register_all_(JSContext* cx, JS::HandleObject obj);
bool js__GDebugLoadScene_updateLabel(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDebugLoadScene_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDebugLoadScene_loadBase(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDebugLoadScene_preload(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDebugLoadScene_loadCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDebugLoadScene_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDebugLoadScene_preloadCallback(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GGameControl_class;
extern JSObject *jsb_GGameControl_prototype;

bool js__GGameControl_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js__GGameControl_finalize(JSContext *cx, JSObject *obj);
void js_register__GGameControl(JSContext *cx, JS::HandleObject global);
void register_all_(JSContext* cx, JS::HandleObject obj);
bool js__GGameControl_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GGameControl_run(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GGameControl_includeScript(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GGameControl_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GResource_class;
extern JSObject *jsb_GResource_prototype;

bool js__GResource_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js__GResource_finalize(JSContext *cx, JSObject *obj);
void js_register__GResource(JSContext *cx, JS::HandleObject global);
void register_all_(JSContext* cx, JS::HandleObject obj);
bool js__GResource_copyFile(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_getCachePath(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_decryption(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_getWritePath(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_getWriteResPath(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_decompress(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_removeFile(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_getResUrl(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_getCodeUrl(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_baseDir(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_createDirForUrlFile(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_baseFileName(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_getWriteCodePath(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_isFile(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_getTempPath(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_write_file(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_append_file(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_read_file(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GResource_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GUTF8_class;
extern JSObject *jsb_GUTF8_prototype;

bool js__GUTF8_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js__GUTF8_finalize(JSContext *cx, JSObject *obj);
void js_register__GUTF8(JSContext *cx, JS::HandleObject global);
void register_all_(JSContext* cx, JS::HandleObject obj);

extern JSClass  *jsb_GLogger_class;
extern JSObject *jsb_GLogger_prototype;

bool js__GLogger_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js__GLogger_finalize(JSContext *cx, JSObject *obj);
void js_register__GLogger(JSContext *cx, JS::HandleObject global);
void register_all_(JSContext* cx, JS::HandleObject obj);
bool js__GLogger_debug(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GLogger_error(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GLogger_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GDeviceInfo_class;
extern JSObject *jsb_GDeviceInfo_prototype;

bool js__GDeviceInfo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js__GDeviceInfo_finalize(JSContext *cx, JSObject *obj);
void js_register__GDeviceInfo(JSContext *cx, JS::HandleObject global);
void register_all_(JSContext* cx, JS::HandleObject obj);
bool js__GDeviceInfo_cpu_usage(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_device_uuid(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_os_is_android(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_getSDPath(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_memory_all(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_version_js(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_os_is_ios(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_device_network(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_cpu_core(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_device_hardware(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_uuid(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_vibrate(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_os_is_wp(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_isSDEnable(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_mode_release(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_memory_used(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_memory_free(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_browser_useragent(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_keyboard_exist(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_device_telecom(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_version_resource(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_open_browser(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_mode_debug(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_os_is_html5(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_keyboard_close(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_keep_awake(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfo_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GDeviceInfoAndroid_class;
extern JSObject *jsb_GDeviceInfoAndroid_prototype;

bool js__GDeviceInfoAndroid_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js__GDeviceInfoAndroid_finalize(JSContext *cx, JSObject *obj);
void js_register__GDeviceInfoAndroid(JSContext *cx, JS::HandleObject global);
void register_all_(JSContext* cx, JS::HandleObject obj);
bool js__GDeviceInfoAndroid_memory_used(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_cpu_usage(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_memory_free(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_keyboard_close(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_browser_useragent(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_isSDEnable(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_vibrate(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_getSDPath(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_device_telecom(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_device_network(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_keep_awake(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_open_browser(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_device_hardware(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_keyboard_exist(JSContext *cx, uint32_t argc, jsval *vp);
bool js__GDeviceInfoAndroid_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

#endif // ___h__
