#include "jsb_libguang_auto.hpp"
#include "cocos2d_specifics.hpp"
#include "guang.h"

template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    JS::RootedObject global(cx, ScriptingCore::getInstance()->getGlobalObject());
    isNewValid = JS_GetProperty(cx, global, "initializing", &initializing) && initializing.toBoolean();
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
        
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    JS_ReportError(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;    
}
JSClass  *jsb_GHtttpService_class;
JSObject *jsb_GHtttpService_prototype;

bool js_libguang_GHtttpService_download(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GHtttpService* cobj = (GHtttpService *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GHtttpService_download : Invalid Native Object");
    if (argc == 1) {
        GHttpTask* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JSObject *tmpObj = args.get(0).toObjectOrNull();
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (GHttpTask*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GHtttpService_download : Error processing arguments");
        cobj->download(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GHtttpService_download : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GHtttpService_asyncDownload(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GHtttpService* cobj = (GHtttpService *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GHtttpService_asyncDownload : Invalid Native Object");
    if (argc == 1) {
        GHttpTask* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JSObject *tmpObj = args.get(0).toObjectOrNull();
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (GHttpTask*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GHtttpService_asyncDownload : Error processing arguments");
        cobj->asyncDownload(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GHtttpService_asyncDownload : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GHtttpService_request(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GHtttpService* cobj = (GHtttpService *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GHtttpService_request : Invalid Native Object");
    if (argc == 1) {
        GHttpTask* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JSObject *tmpObj = args.get(0).toObjectOrNull();
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (GHttpTask*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GHtttpService_request : Error processing arguments");
        cobj->request(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GHtttpService_request : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GHtttpService_destroy(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        GHtttpService::destroy();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_libguang_GHtttpService_destroy : wrong number of arguments");
    return false;
}

bool js_libguang_GHtttpService_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        GHtttpService* ret = GHtttpService::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<GHtttpService>(cx, (GHtttpService*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GHtttpService_getInstance : wrong number of arguments");
    return false;
}


void js_GHtttpService_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (GHtttpService)", obj);
}
void js_register_libguang_GHtttpService(JSContext *cx, JS::HandleObject global) {
    jsb_GHtttpService_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_GHtttpService_class->name = "GHtttpService";
    jsb_GHtttpService_class->addProperty = JS_PropertyStub;
    jsb_GHtttpService_class->delProperty = JS_DeletePropertyStub;
    jsb_GHtttpService_class->getProperty = JS_PropertyStub;
    jsb_GHtttpService_class->setProperty = JS_StrictPropertyStub;
    jsb_GHtttpService_class->enumerate = JS_EnumerateStub;
    jsb_GHtttpService_class->resolve = JS_ResolveStub;
    jsb_GHtttpService_class->convert = JS_ConvertStub;
    jsb_GHtttpService_class->finalize = js_GHtttpService_finalize;
    jsb_GHtttpService_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("download", js_libguang_GHtttpService_download, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("asyncDownload", js_libguang_GHtttpService_asyncDownload, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("request", js_libguang_GHtttpService_request, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("destroy", js_libguang_GHtttpService_destroy, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getInstance", js_libguang_GHtttpService_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_GHtttpService_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_GHtttpService_class,
        dummy_constructor<GHtttpService>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "GHtttpService", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<GHtttpService> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_GHtttpService_class;
        p->proto = jsb_GHtttpService_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_GStartLoadScene_class;
JSObject *jsb_GStartLoadScene_prototype;

bool js_libguang_GStartLoadScene_updateLabel(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GStartLoadScene* cobj = (GStartLoadScene *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GStartLoadScene_updateLabel : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GStartLoadScene_updateLabel : Error processing arguments");
        cobj->updateLabel(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GStartLoadScene_updateLabel : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GStartLoadScene_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GStartLoadScene* cobj = (GStartLoadScene *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GStartLoadScene_init : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GStartLoadScene_init : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GStartLoadScene_decData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GStartLoadScene* cobj = (GStartLoadScene *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GStartLoadScene_decData : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GStartLoadScene_decData : Error processing arguments");
        cobj->decData(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GStartLoadScene_decData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GStartLoadScene_create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        GStartLoadScene* ret = GStartLoadScene::create();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<GStartLoadScene>(cx, (GStartLoadScene*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GStartLoadScene_create : wrong number of arguments");
    return false;
}


extern JSObject *jsb_cocos2d_Scene_prototype;

void js_GStartLoadScene_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (GStartLoadScene)", obj);
}
void js_register_libguang_GStartLoadScene(JSContext *cx, JS::HandleObject global) {
    jsb_GStartLoadScene_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_GStartLoadScene_class->name = "GStartLoadScene";
    jsb_GStartLoadScene_class->addProperty = JS_PropertyStub;
    jsb_GStartLoadScene_class->delProperty = JS_DeletePropertyStub;
    jsb_GStartLoadScene_class->getProperty = JS_PropertyStub;
    jsb_GStartLoadScene_class->setProperty = JS_StrictPropertyStub;
    jsb_GStartLoadScene_class->enumerate = JS_EnumerateStub;
    jsb_GStartLoadScene_class->resolve = JS_ResolveStub;
    jsb_GStartLoadScene_class->convert = JS_ConvertStub;
    jsb_GStartLoadScene_class->finalize = js_GStartLoadScene_finalize;
    jsb_GStartLoadScene_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("updateLabel", js_libguang_GStartLoadScene_updateLabel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_libguang_GStartLoadScene_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("decData", js_libguang_GStartLoadScene_decData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("create", js_libguang_GStartLoadScene_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_GStartLoadScene_prototype = JS_InitClass(
        cx, global,
        JS::RootedObject(cx, jsb_cocos2d_Scene_prototype),
        jsb_GStartLoadScene_class,
        dummy_constructor<GStartLoadScene>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "GStartLoadScene", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<GStartLoadScene> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_GStartLoadScene_class;
        p->proto = jsb_GStartLoadScene_prototype;
        p->parentProto = jsb_cocos2d_Scene_prototype;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_GDebugLoadScene_class;
JSObject *jsb_GDebugLoadScene_prototype;

bool js_libguang_GDebugLoadScene_updateLabel(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDebugLoadScene* cobj = (GDebugLoadScene *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDebugLoadScene_updateLabel : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GDebugLoadScene_updateLabel : Error processing arguments");
        cobj->updateLabel(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDebugLoadScene_updateLabel : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GDebugLoadScene_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDebugLoadScene* cobj = (GDebugLoadScene *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDebugLoadScene_init : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDebugLoadScene_init : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDebugLoadScene_loadBase(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDebugLoadScene* cobj = (GDebugLoadScene *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDebugLoadScene_loadBase : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GDebugLoadScene_loadBase : Error processing arguments");
        cobj->loadBase(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDebugLoadScene_loadBase : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GDebugLoadScene_preload(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GDebugLoadScene_preload : Error processing arguments");
        bool ret = GDebugLoadScene::preload(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GDebugLoadScene_preload : wrong number of arguments");
    return false;
}

bool js_libguang_GDebugLoadScene_loadCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GDebugLoadScene_loadCallback : Error processing arguments");
        GDebugLoadScene::loadCallback(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_libguang_GDebugLoadScene_loadCallback : wrong number of arguments");
    return false;
}

bool js_libguang_GDebugLoadScene_create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        GDebugLoadScene* ret = GDebugLoadScene::create();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<GDebugLoadScene>(cx, (GDebugLoadScene*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GDebugLoadScene_create : wrong number of arguments");
    return false;
}

bool js_libguang_GDebugLoadScene_preloadCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GDebugLoadScene_preloadCallback : Error processing arguments");
        GDebugLoadScene::preloadCallback(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_libguang_GDebugLoadScene_preloadCallback : wrong number of arguments");
    return false;
}


extern JSObject *jsb_cocos2d_Scene_prototype;

void js_GDebugLoadScene_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (GDebugLoadScene)", obj);
}
void js_register_libguang_GDebugLoadScene(JSContext *cx, JS::HandleObject global) {
    jsb_GDebugLoadScene_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_GDebugLoadScene_class->name = "GDebugLoadScene";
    jsb_GDebugLoadScene_class->addProperty = JS_PropertyStub;
    jsb_GDebugLoadScene_class->delProperty = JS_DeletePropertyStub;
    jsb_GDebugLoadScene_class->getProperty = JS_PropertyStub;
    jsb_GDebugLoadScene_class->setProperty = JS_StrictPropertyStub;
    jsb_GDebugLoadScene_class->enumerate = JS_EnumerateStub;
    jsb_GDebugLoadScene_class->resolve = JS_ResolveStub;
    jsb_GDebugLoadScene_class->convert = JS_ConvertStub;
    jsb_GDebugLoadScene_class->finalize = js_GDebugLoadScene_finalize;
    jsb_GDebugLoadScene_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("updateLabel", js_libguang_GDebugLoadScene_updateLabel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_libguang_GDebugLoadScene_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadBase", js_libguang_GDebugLoadScene_loadBase, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("preload", js_libguang_GDebugLoadScene_preload, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("loadCallback", js_libguang_GDebugLoadScene_loadCallback, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("create", js_libguang_GDebugLoadScene_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("preloadCallback", js_libguang_GDebugLoadScene_preloadCallback, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_GDebugLoadScene_prototype = JS_InitClass(
        cx, global,
        JS::RootedObject(cx, jsb_cocos2d_Scene_prototype),
        jsb_GDebugLoadScene_class,
        dummy_constructor<GDebugLoadScene>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "GDebugLoadScene", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<GDebugLoadScene> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_GDebugLoadScene_class;
        p->proto = jsb_GDebugLoadScene_prototype;
        p->parentProto = jsb_cocos2d_Scene_prototype;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_GGameControl_class;
JSObject *jsb_GGameControl_prototype;

bool js_libguang_GGameControl_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GGameControl* cobj = (GGameControl *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GGameControl_init : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GGameControl_init : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GGameControl_run(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GGameControl* cobj = (GGameControl *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GGameControl_run : Invalid Native Object");
    if (argc == 0) {
        cobj->run();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GGameControl_run : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GGameControl_includeScript(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 3) {
        JSContext* arg0 = nullptr;
        unsigned int arg1 = 0;
        JS::Value* arg2 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR JSContext*
		ok = false;
        ok &= jsval_to_uint32(cx, args.get(1), &arg1);
        do {
            if (args.get(2).isNull()) { arg2 = nullptr; break; }
            if (!args.get(2).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JSObject *tmpObj = args.get(2).toObjectOrNull();
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg2 = (jsval*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg2, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GGameControl_includeScript : Error processing arguments");
        bool ret = GGameControl::includeScript(arg0, arg1, arg2);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GGameControl_includeScript : wrong number of arguments");
    return false;
}

bool js_libguang_GGameControl_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        GGameControl* ret = GGameControl::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<GGameControl>(cx, (GGameControl*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GGameControl_getInstance : wrong number of arguments");
    return false;
}


void js_GGameControl_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (GGameControl)", obj);
}
void js_register_libguang_GGameControl(JSContext *cx, JS::HandleObject global) {
    jsb_GGameControl_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_GGameControl_class->name = "GGameControl";
    jsb_GGameControl_class->addProperty = JS_PropertyStub;
    jsb_GGameControl_class->delProperty = JS_DeletePropertyStub;
    jsb_GGameControl_class->getProperty = JS_PropertyStub;
    jsb_GGameControl_class->setProperty = JS_StrictPropertyStub;
    jsb_GGameControl_class->enumerate = JS_EnumerateStub;
    jsb_GGameControl_class->resolve = JS_ResolveStub;
    jsb_GGameControl_class->convert = JS_ConvertStub;
    jsb_GGameControl_class->finalize = js_GGameControl_finalize;
    jsb_GGameControl_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("init", js_libguang_GGameControl_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("run", js_libguang_GGameControl_run, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("includeScript", js_libguang_GGameControl_includeScript, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getInstance", js_libguang_GGameControl_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_GGameControl_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_GGameControl_class,
        dummy_constructor<GGameControl>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "GGameControl", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<GGameControl> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_GGameControl_class;
        p->proto = jsb_GGameControl_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_GResource_class;
JSObject *jsb_GResource_prototype;

bool js_libguang_GResource_copyFile(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_copyFile : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_copyFile : Error processing arguments");
        bool ret = cobj->copyFile(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_copyFile : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_libguang_GResource_getCachePath(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_getCachePath : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getCachePath();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_getCachePath : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GResource_decryption(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_decryption : Invalid Native Object");
    if (argc == 2) {
        char* arg0 = nullptr;
        int arg1 = 0;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_decryption : Error processing arguments");
        bool ret = cobj->decryption(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_decryption : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_libguang_GResource_getWritePath(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_getWritePath : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getWritePath();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_getWritePath : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GResource_getWriteResPath(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_getWriteResPath : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getWriteResPath();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_getWriteResPath : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GResource_decompress(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_decompress : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_decompress : Error processing arguments");
        bool ret = cobj->decompress(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_decompress : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_libguang_GResource_removeFile(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_removeFile : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_removeFile : Error processing arguments");
        bool ret = cobj->removeFile(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_removeFile : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GResource_getResUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_getResUrl : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getResUrl();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_getResUrl : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GResource_getCodeUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_getCodeUrl : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getCodeUrl();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_getCodeUrl : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GResource_baseDir(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_baseDir : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_baseDir : Error processing arguments");
        std::string ret = cobj->baseDir(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_baseDir : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GResource_createDirForUrlFile(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_createDirForUrlFile : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_createDirForUrlFile : Error processing arguments");
        bool ret = cobj->createDirForUrlFile(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_createDirForUrlFile : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_libguang_GResource_baseFileName(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_baseFileName : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_baseFileName : Error processing arguments");
        std::string ret = cobj->baseFileName(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_baseFileName : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GResource_getWriteCodePath(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_getWriteCodePath : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getWriteCodePath();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_getWriteCodePath : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GResource_isFile(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_isFile : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_isFile : Error processing arguments");
        bool ret = cobj->isFile(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_isFile : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GResource_getTempPath(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GResource* cobj = (GResource *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GResource_getTempPath : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getTempPath();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GResource_getTempPath : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GResource_write_file(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 3) {
        std::string arg0;
        const unsigned char* arg1 = nullptr;
        unsigned int arg2 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;
        ok &= jsval_to_uint32(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_write_file : Error processing arguments");
        bool ret = GResource::write_file(arg0, arg1, arg2);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GResource_write_file : wrong number of arguments");
    return false;
}

bool js_libguang_GResource_append_file(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 3) {
        std::string arg0;
        const unsigned char* arg1 = nullptr;
        unsigned int arg2 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        #pragma warning NO CONVERSION TO NATIVE FOR unsigned char*
		ok = false;
        ok &= jsval_to_uint32(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_append_file : Error processing arguments");
        bool ret = GResource::append_file(arg0, arg1, arg2);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GResource_append_file : wrong number of arguments");
    return false;
}

bool js_libguang_GResource_read_file(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_read_file : Error processing arguments");
        cocos2d::Data ret = GResource::read_file(arg0);
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Data>(cx, (cocos2d::Data)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        unsigned int arg1 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_uint32(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_read_file : Error processing arguments");
        cocos2d::Data ret = GResource::read_file(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Data>(cx, (cocos2d::Data)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        unsigned int arg1 = 0;
        unsigned int arg2 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_uint32(cx, args.get(1), &arg1);
        ok &= jsval_to_uint32(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GResource_read_file : Error processing arguments");
        cocos2d::Data ret = GResource::read_file(arg0, arg1, arg2);
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Data>(cx, (cocos2d::Data)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GResource_read_file : wrong number of arguments");
    return false;
}

bool js_libguang_GResource_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        GResource* ret = GResource::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<GResource>(cx, (GResource*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GResource_getInstance : wrong number of arguments");
    return false;
}


void js_GResource_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (GResource)", obj);
}
void js_register_libguang_GResource(JSContext *cx, JS::HandleObject global) {
    jsb_GResource_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_GResource_class->name = "GResource";
    jsb_GResource_class->addProperty = JS_PropertyStub;
    jsb_GResource_class->delProperty = JS_DeletePropertyStub;
    jsb_GResource_class->getProperty = JS_PropertyStub;
    jsb_GResource_class->setProperty = JS_StrictPropertyStub;
    jsb_GResource_class->enumerate = JS_EnumerateStub;
    jsb_GResource_class->resolve = JS_ResolveStub;
    jsb_GResource_class->convert = JS_ConvertStub;
    jsb_GResource_class->finalize = js_GResource_finalize;
    jsb_GResource_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("copyFile", js_libguang_GResource_copyFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCachePath", js_libguang_GResource_getCachePath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("decryption", js_libguang_GResource_decryption, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getWritePath", js_libguang_GResource_getWritePath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getWriteResPath", js_libguang_GResource_getWriteResPath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("decompress", js_libguang_GResource_decompress, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeFile", js_libguang_GResource_removeFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getResUrl", js_libguang_GResource_getResUrl, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCodeUrl", js_libguang_GResource_getCodeUrl, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("baseDir", js_libguang_GResource_baseDir, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("createDirForUrlFile", js_libguang_GResource_createDirForUrlFile, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("baseFileName", js_libguang_GResource_baseFileName, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getWriteCodePath", js_libguang_GResource_getWriteCodePath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isFile", js_libguang_GResource_isFile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getTempPath", js_libguang_GResource_getTempPath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("write_file", js_libguang_GResource_write_file, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("append_file", js_libguang_GResource_append_file, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("read_file", js_libguang_GResource_read_file, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getInstance", js_libguang_GResource_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_GResource_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_GResource_class,
        dummy_constructor<GResource>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "GResource", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<GResource> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_GResource_class;
        p->proto = jsb_GResource_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_GUTF8_class;
JSObject *jsb_GUTF8_prototype;


void js_GUTF8_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (GUTF8)", obj);
}
void js_register_libguang_GUTF8(JSContext *cx, JS::HandleObject global) {
    jsb_GUTF8_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_GUTF8_class->name = "GUTF8";
    jsb_GUTF8_class->addProperty = JS_PropertyStub;
    jsb_GUTF8_class->delProperty = JS_DeletePropertyStub;
    jsb_GUTF8_class->getProperty = JS_PropertyStub;
    jsb_GUTF8_class->setProperty = JS_StrictPropertyStub;
    jsb_GUTF8_class->enumerate = JS_EnumerateStub;
    jsb_GUTF8_class->resolve = JS_ResolveStub;
    jsb_GUTF8_class->convert = JS_ConvertStub;
    jsb_GUTF8_class->finalize = js_GUTF8_finalize;
    jsb_GUTF8_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_GUTF8_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_GUTF8_class,
        dummy_constructor<GUTF8>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "GUTF8", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<GUTF8> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_GUTF8_class;
        p->proto = jsb_GUTF8_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_GLogger_class;
JSObject *jsb_GLogger_prototype;

bool js_libguang_GLogger_debug(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GLogger* cobj = (GLogger *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GLogger_debug : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GLogger_debug : Error processing arguments");
        cobj->debug(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GLogger_debug : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GLogger_error(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GLogger* cobj = (GLogger *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GLogger_error : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GLogger_error : Error processing arguments");
        cobj->error(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GLogger_error : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GLogger_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        GLogger* ret = GLogger::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<GLogger>(cx, (GLogger*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GLogger_getInstance : wrong number of arguments");
    return false;
}


void js_GLogger_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (GLogger)", obj);
}
void js_register_libguang_GLogger(JSContext *cx, JS::HandleObject global) {
    jsb_GLogger_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_GLogger_class->name = "GLogger";
    jsb_GLogger_class->addProperty = JS_PropertyStub;
    jsb_GLogger_class->delProperty = JS_DeletePropertyStub;
    jsb_GLogger_class->getProperty = JS_PropertyStub;
    jsb_GLogger_class->setProperty = JS_StrictPropertyStub;
    jsb_GLogger_class->enumerate = JS_EnumerateStub;
    jsb_GLogger_class->resolve = JS_ResolveStub;
    jsb_GLogger_class->convert = JS_ConvertStub;
    jsb_GLogger_class->finalize = js_GLogger_finalize;
    jsb_GLogger_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("debug", js_libguang_GLogger_debug, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("error", js_libguang_GLogger_error, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getInstance", js_libguang_GLogger_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_GLogger_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_GLogger_class,
        dummy_constructor<GLogger>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "GLogger", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<GLogger> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_GLogger_class;
        p->proto = jsb_GLogger_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_GDeviceInfo_class;
JSObject *jsb_GDeviceInfo_prototype;

bool js_libguang_GDeviceInfo_cpu_usage(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_cpu_usage : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->cpu_usage();
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_cpu_usage : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_device_uuid(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_device_uuid : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->device_uuid();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_device_uuid : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_os_is_android(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_os_is_android : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->os_is_android();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_os_is_android : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_getSDPath(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_getSDPath : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getSDPath();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_getSDPath : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_memory_all(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_memory_all : Invalid Native Object");
    if (argc == 0) {
        unsigned int ret = cobj->memory_all();
        jsval jsret = JSVAL_NULL;
        jsret = uint32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_memory_all : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_version_js(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_version_js : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->version_js();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_version_js : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_os_is_ios(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_os_is_ios : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->os_is_ios();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_os_is_ios : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_device_network(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_device_network : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->device_network();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_device_network : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_cpu_core(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_cpu_core : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->cpu_core();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_cpu_core : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_device_hardware(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_device_hardware : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->device_hardware();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_device_hardware : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_uuid(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_uuid : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->uuid();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_uuid : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_vibrate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_vibrate : Invalid Native Object");
    if (argc == 0) {
        cobj->vibrate();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_vibrate : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_os_is_wp(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_os_is_wp : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->os_is_wp();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_os_is_wp : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_isSDEnable(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_isSDEnable : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isSDEnable();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_isSDEnable : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_mode_release(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_mode_release : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->mode_release();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_mode_release : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_memory_used(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_memory_used : Invalid Native Object");
    if (argc == 0) {
        unsigned int ret = cobj->memory_used();
        jsval jsret = JSVAL_NULL;
        jsret = uint32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_memory_used : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_memory_free(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_memory_free : Invalid Native Object");
    if (argc == 0) {
        unsigned int ret = cobj->memory_free();
        jsval jsret = JSVAL_NULL;
        jsret = uint32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_memory_free : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_browser_useragent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_browser_useragent : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->browser_useragent();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_browser_useragent : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_keyboard_exist(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_keyboard_exist : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->keyboard_exist();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_keyboard_exist : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_device_telecom(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_device_telecom : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->device_telecom();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_device_telecom : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_version_resource(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_version_resource : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->version_resource();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_version_resource : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_open_browser(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_open_browser : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GDeviceInfo_open_browser : Error processing arguments");
        cobj->open_browser(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_open_browser : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GDeviceInfo_mode_debug(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_mode_debug : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->mode_debug();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_mode_debug : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_os_is_html5(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_os_is_html5 : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->os_is_html5();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_os_is_html5 : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_keyboard_close(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_keyboard_close : Invalid Native Object");
    if (argc == 0) {
        cobj->keyboard_close();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_keyboard_close : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfo_keep_awake(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfo* cobj = (GDeviceInfo *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfo_keep_awake : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GDeviceInfo_keep_awake : Error processing arguments");
        cobj->keep_awake(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfo_keep_awake : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GDeviceInfo_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        GDeviceInfo* ret = GDeviceInfo::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<GDeviceInfo>(cx, (GDeviceInfo*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GDeviceInfo_getInstance : wrong number of arguments");
    return false;
}


void js_GDeviceInfo_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (GDeviceInfo)", obj);
}
void js_register_libguang_GDeviceInfo(JSContext *cx, JS::HandleObject global) {
    jsb_GDeviceInfo_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_GDeviceInfo_class->name = "GDeviceInfo";
    jsb_GDeviceInfo_class->addProperty = JS_PropertyStub;
    jsb_GDeviceInfo_class->delProperty = JS_DeletePropertyStub;
    jsb_GDeviceInfo_class->getProperty = JS_PropertyStub;
    jsb_GDeviceInfo_class->setProperty = JS_StrictPropertyStub;
    jsb_GDeviceInfo_class->enumerate = JS_EnumerateStub;
    jsb_GDeviceInfo_class->resolve = JS_ResolveStub;
    jsb_GDeviceInfo_class->convert = JS_ConvertStub;
    jsb_GDeviceInfo_class->finalize = js_GDeviceInfo_finalize;
    jsb_GDeviceInfo_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("cpu_usage", js_libguang_GDeviceInfo_cpu_usage, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("device_uuid", js_libguang_GDeviceInfo_device_uuid, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("os_is_android", js_libguang_GDeviceInfo_os_is_android, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSDPath", js_libguang_GDeviceInfo_getSDPath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("memory_all", js_libguang_GDeviceInfo_memory_all, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("version_js", js_libguang_GDeviceInfo_version_js, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("os_is_ios", js_libguang_GDeviceInfo_os_is_ios, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("device_network", js_libguang_GDeviceInfo_device_network, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cpu_core", js_libguang_GDeviceInfo_cpu_core, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("device_hardware", js_libguang_GDeviceInfo_device_hardware, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("uuid", js_libguang_GDeviceInfo_uuid, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("vibrate", js_libguang_GDeviceInfo_vibrate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("os_is_wp", js_libguang_GDeviceInfo_os_is_wp, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isSDEnable", js_libguang_GDeviceInfo_isSDEnable, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("mode_release", js_libguang_GDeviceInfo_mode_release, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("memory_used", js_libguang_GDeviceInfo_memory_used, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("memory_free", js_libguang_GDeviceInfo_memory_free, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("browser_useragent", js_libguang_GDeviceInfo_browser_useragent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("keyboard_exist", js_libguang_GDeviceInfo_keyboard_exist, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("device_telecom", js_libguang_GDeviceInfo_device_telecom, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("version_resource", js_libguang_GDeviceInfo_version_resource, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("open_browser", js_libguang_GDeviceInfo_open_browser, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("mode_debug", js_libguang_GDeviceInfo_mode_debug, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("os_is_html5", js_libguang_GDeviceInfo_os_is_html5, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("keyboard_close", js_libguang_GDeviceInfo_keyboard_close, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("keep_awake", js_libguang_GDeviceInfo_keep_awake, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getInstance", js_libguang_GDeviceInfo_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_GDeviceInfo_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_GDeviceInfo_class,
        dummy_constructor<GDeviceInfo>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "GDeviceInfo", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<GDeviceInfo> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_GDeviceInfo_class;
        p->proto = jsb_GDeviceInfo_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_GDeviceInfoAndroid_class;
JSObject *jsb_GDeviceInfoAndroid_prototype;

bool js_libguang_GDeviceInfoAndroid_memory_used(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_memory_used : Invalid Native Object");
    if (argc == 0) {
        unsigned int ret = cobj->memory_used();
        jsval jsret = JSVAL_NULL;
        jsret = uint32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_memory_used : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_cpu_usage(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_cpu_usage : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->cpu_usage();
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_cpu_usage : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_memory_free(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_memory_free : Invalid Native Object");
    if (argc == 0) {
        unsigned int ret = cobj->memory_free();
        jsval jsret = JSVAL_NULL;
        jsret = uint32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_memory_free : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_keyboard_close(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_keyboard_close : Invalid Native Object");
    if (argc == 0) {
        cobj->keyboard_close();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_keyboard_close : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_browser_useragent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_browser_useragent : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->browser_useragent();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_browser_useragent : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_isSDEnable(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_isSDEnable : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isSDEnable();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_isSDEnable : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_vibrate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_vibrate : Invalid Native Object");
    if (argc == 0) {
        cobj->vibrate();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_vibrate : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_getSDPath(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_getSDPath : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getSDPath();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_getSDPath : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_device_telecom(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_device_telecom : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->device_telecom();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_device_telecom : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_device_network(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_device_network : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->device_network();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_device_network : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_keep_awake(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_keep_awake : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GDeviceInfoAndroid_keep_awake : Error processing arguments");
        cobj->keep_awake(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_keep_awake : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_open_browser(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_open_browser : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_libguang_GDeviceInfoAndroid_open_browser : Error processing arguments");
        cobj->open_browser(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_open_browser : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_device_hardware(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_device_hardware : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->device_hardware();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_device_hardware : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_keyboard_exist(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    GDeviceInfoAndroid* cobj = (GDeviceInfoAndroid *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_libguang_GDeviceInfoAndroid_keyboard_exist : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->keyboard_exist();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_keyboard_exist : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_libguang_GDeviceInfoAndroid_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        GDeviceInfoAndroid* ret = GDeviceInfoAndroid::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<GDeviceInfoAndroid>(cx, (GDeviceInfoAndroid*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_libguang_GDeviceInfoAndroid_getInstance : wrong number of arguments");
    return false;
}


extern JSObject *jsb_GDeviceInfo_prototype;

void js_GDeviceInfoAndroid_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (GDeviceInfoAndroid)", obj);
}
void js_register_libguang_GDeviceInfoAndroid(JSContext *cx, JS::HandleObject global) {
    jsb_GDeviceInfoAndroid_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_GDeviceInfoAndroid_class->name = "GDeviceInfoAndroid";
    jsb_GDeviceInfoAndroid_class->addProperty = JS_PropertyStub;
    jsb_GDeviceInfoAndroid_class->delProperty = JS_DeletePropertyStub;
    jsb_GDeviceInfoAndroid_class->getProperty = JS_PropertyStub;
    jsb_GDeviceInfoAndroid_class->setProperty = JS_StrictPropertyStub;
    jsb_GDeviceInfoAndroid_class->enumerate = JS_EnumerateStub;
    jsb_GDeviceInfoAndroid_class->resolve = JS_ResolveStub;
    jsb_GDeviceInfoAndroid_class->convert = JS_ConvertStub;
    jsb_GDeviceInfoAndroid_class->finalize = js_GDeviceInfoAndroid_finalize;
    jsb_GDeviceInfoAndroid_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("memory_used", js_libguang_GDeviceInfoAndroid_memory_used, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("cpu_usage", js_libguang_GDeviceInfoAndroid_cpu_usage, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("memory_free", js_libguang_GDeviceInfoAndroid_memory_free, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("keyboard_close", js_libguang_GDeviceInfoAndroid_keyboard_close, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("browser_useragent", js_libguang_GDeviceInfoAndroid_browser_useragent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isSDEnable", js_libguang_GDeviceInfoAndroid_isSDEnable, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("vibrate", js_libguang_GDeviceInfoAndroid_vibrate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSDPath", js_libguang_GDeviceInfoAndroid_getSDPath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("device_telecom", js_libguang_GDeviceInfoAndroid_device_telecom, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("device_network", js_libguang_GDeviceInfoAndroid_device_network, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("keep_awake", js_libguang_GDeviceInfoAndroid_keep_awake, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("open_browser", js_libguang_GDeviceInfoAndroid_open_browser, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("device_hardware", js_libguang_GDeviceInfoAndroid_device_hardware, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("keyboard_exist", js_libguang_GDeviceInfoAndroid_keyboard_exist, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getInstance", js_libguang_GDeviceInfoAndroid_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_GDeviceInfoAndroid_prototype = JS_InitClass(
        cx, global,
        JS::RootedObject(cx, jsb_GDeviceInfo_prototype),
        jsb_GDeviceInfoAndroid_class,
        dummy_constructor<GDeviceInfoAndroid>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "GDeviceInfoAndroid", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<GDeviceInfoAndroid> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_GDeviceInfoAndroid_class;
        p->proto = jsb_GDeviceInfoAndroid_prototype;
        p->parentProto = jsb_GDeviceInfo_prototype;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

void register_all_libguang(JSContext* cx, JS::HandleObject obj) {
    // Get the global ns
    JS::RootedObject ns(cx, ScriptingCore::getInstance()->getGlobalObject());

    js_register_libguang_GDeviceInfo(cx, ns);
    js_register_libguang_GDeviceInfoAndroid(cx, ns);
    js_register_libguang_GGameControl(cx, ns);
    js_register_libguang_GResource(cx, ns);
    js_register_libguang_GLogger(cx, ns);
    js_register_libguang_GUTF8(cx, ns);
    js_register_libguang_GHtttpService(cx, ns);
    js_register_libguang_GStartLoadScene(cx, ns);
    js_register_libguang_GDebugLoadScene(cx, ns);
}

