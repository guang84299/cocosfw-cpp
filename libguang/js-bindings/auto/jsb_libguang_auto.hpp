#include "base/ccConfig.h"
#ifndef __libguang_h__
#define __libguang_h__

#include "jsapi.h"
#include "jsfriendapi.h"

extern JSClass  *jsb_GHtttpService_class;
extern JSObject *jsb_GHtttpService_prototype;

bool js_libguang_GHtttpService_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_libguang_GHtttpService_finalize(JSContext *cx, JSObject *obj);
void js_register_libguang_GHtttpService(JSContext *cx, JS::HandleObject global);
void register_all_libguang(JSContext* cx, JS::HandleObject obj);
bool js_libguang_GHtttpService_download(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GHtttpService_asyncDownload(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GHtttpService_request(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GHtttpService_destroy(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GHtttpService_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GStartLoadScene_class;
extern JSObject *jsb_GStartLoadScene_prototype;

bool js_libguang_GStartLoadScene_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_libguang_GStartLoadScene_finalize(JSContext *cx, JSObject *obj);
void js_register_libguang_GStartLoadScene(JSContext *cx, JS::HandleObject global);
void register_all_libguang(JSContext* cx, JS::HandleObject obj);
bool js_libguang_GStartLoadScene_updateLabel(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GStartLoadScene_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GStartLoadScene_decData(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GStartLoadScene_create(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GDebugLoadScene_class;
extern JSObject *jsb_GDebugLoadScene_prototype;

bool js_libguang_GDebugLoadScene_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_libguang_GDebugLoadScene_finalize(JSContext *cx, JSObject *obj);
void js_register_libguang_GDebugLoadScene(JSContext *cx, JS::HandleObject global);
void register_all_libguang(JSContext* cx, JS::HandleObject obj);
bool js_libguang_GDebugLoadScene_updateLabel(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDebugLoadScene_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDebugLoadScene_loadBase(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDebugLoadScene_preload(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDebugLoadScene_loadCallback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDebugLoadScene_create(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDebugLoadScene_preloadCallback(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GGameControl_class;
extern JSObject *jsb_GGameControl_prototype;

bool js_libguang_GGameControl_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_libguang_GGameControl_finalize(JSContext *cx, JSObject *obj);
void js_register_libguang_GGameControl(JSContext *cx, JS::HandleObject global);
void register_all_libguang(JSContext* cx, JS::HandleObject obj);
bool js_libguang_GGameControl_init(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GGameControl_run(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GGameControl_includeScript(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GGameControl_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GResource_class;
extern JSObject *jsb_GResource_prototype;

bool js_libguang_GResource_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_libguang_GResource_finalize(JSContext *cx, JSObject *obj);
void js_register_libguang_GResource(JSContext *cx, JS::HandleObject global);
void register_all_libguang(JSContext* cx, JS::HandleObject obj);
bool js_libguang_GResource_getCachePath(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_getWritePath(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_getWriteResPath(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_getResUrl(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_getCodeUrl(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_createDirForUrlFile(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_getWriteCodePath(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_getTempPath(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_copyFile(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_getInstance(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_decryption(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_append_file(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_baseDir(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_decompress(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_removeFile(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_baseFileName(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GResource_isFile(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GUTF8_class;
extern JSObject *jsb_GUTF8_prototype;

bool js_libguang_GUTF8_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_libguang_GUTF8_finalize(JSContext *cx, JSObject *obj);
void js_register_libguang_GUTF8(JSContext *cx, JS::HandleObject global);
void register_all_libguang(JSContext* cx, JS::HandleObject obj);

extern JSClass  *jsb_GLogger_class;
extern JSObject *jsb_GLogger_prototype;

bool js_libguang_GLogger_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_libguang_GLogger_finalize(JSContext *cx, JSObject *obj);
void js_register_libguang_GLogger(JSContext *cx, JS::HandleObject global);
void register_all_libguang(JSContext* cx, JS::HandleObject obj);
bool js_libguang_GLogger_debug(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GLogger_error(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GLogger_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_GDeviceInfo_class;
extern JSObject *jsb_GDeviceInfo_prototype;

bool js_libguang_GDeviceInfo_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_libguang_GDeviceInfo_finalize(JSContext *cx, JSObject *obj);
void js_register_libguang_GDeviceInfo(JSContext *cx, JS::HandleObject global);
void register_all_libguang(JSContext* cx, JS::HandleObject obj);
bool js_libguang_GDeviceInfo_cpu_usage(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_device_uuid(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_os_is_android(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_getSDPath(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_memory_all(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_version_js(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_os_is_ios(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_device_network(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_cpu_core(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_device_hardware(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_uuid(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_vibrate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_os_is_wp(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_isSDEnable(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_mode_release(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_memory_used(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_memory_free(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_browser_useragent(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_keyboard_exist(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_device_telecom(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_version_resource(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_open_browser(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_mode_debug(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_os_is_html5(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_keyboard_close(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_keep_awake(JSContext *cx, uint32_t argc, jsval *vp);
bool js_libguang_GDeviceInfo_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __libguang_h__
