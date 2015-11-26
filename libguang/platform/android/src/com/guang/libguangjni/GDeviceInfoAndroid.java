package com.guang.libguangjni;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.app.ActivityManager;
import android.app.ActivityManager.MemoryInfo;
import android.content.Context;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.os.Handler;
import android.os.Looper;
import android.os.Vibrator;
import android.telephony.TelephonyManager;
import android.view.WindowManager;
import android.webkit.WebView;


public class GDeviceInfoAndroid {

	// ===========================================================
    // Methods
    // ===========================================================  
    /**
     * 已用的内存
     * @return {int}
     */
    public static int memory_used() {
        return (int)(Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory());
    }
    
    /**
     * 剩余的内存
     * @return {int}
     */
    public static int memory_free() {
        ActivityManager activityManager = (ActivityManager)Cocos2dxActivity.getContext().getSystemService(Context.ACTIVITY_SERVICE);
        MemoryInfo memoryInfo = new ActivityManager.MemoryInfo();
        activityManager.getMemoryInfo(memoryInfo);

        return (int)memoryInfo.availMem;
    }

    private static long getTotalCpuTime() { // 获取系统总CPU使用时间
        String[] cpuInfos = null;
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("/proc/stat")), 1000);
            String load = reader.readLine();
            reader.close();
            cpuInfos = load.split(" ");
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        long totalCpu = Long.parseLong(cpuInfos[2])
                + Long.parseLong(cpuInfos[3]) + Long.parseLong(cpuInfos[4])
                + Long.parseLong(cpuInfos[6]) + Long.parseLong(cpuInfos[5])
                + Long.parseLong(cpuInfos[7]) + Long.parseLong(cpuInfos[8]);
        return totalCpu;
    }
     
    private static long getAppCpuTime() { // 获取应用占用的CPU时间
        String[] cpuInfos = null;
        try {
            int pid = android.os.Process.myPid();
            BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("/proc/" + pid + "/stat")), 1000);
            String load = reader.readLine();
            reader.close();
            cpuInfos = load.split(" ");
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        long appCpuTime = Long.parseLong(cpuInfos[13])
                + Long.parseLong(cpuInfos[14]) + Long.parseLong(cpuInfos[15])
                + Long.parseLong(cpuInfos[16]);
        return appCpuTime;
    }
    /*
     * 获取CPU占用率
     */
    public static float cpu_usage() {
    	float use = 0;
    	try {
			use = getAppCpuTime() / getTotalCpuTime();
		} catch (Exception e) {
			
		}
        return use;
    }


    /**
     * 运营商信息
     */
    public static String device_telecom() {
        TelephonyManager telephonyManager = ((TelephonyManager)Cocos2dxActivity.getContext().getSystemService(Context.TELEPHONY_SERVICE));
        return telephonyManager.getNetworkOperatorName();
    }

    /**
     * 手机机型
     */
    public static String device_hardware() {
        // http://developer.android.com/reference/android/os/Build.html
        return android.os.Build.MANUFACTURER + " " + android.os.Build.MODEL;
    }

    /**
     * 网络类型
     */
    public static String device_network() {
        // 检测是否已连接
        ConnectivityManager connectivity = (ConnectivityManager)Cocos2dxActivity.getContext().getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo info = connectivity.getActiveNetworkInfo();

        if ((info == null) || !info.isConnected())
            return "";

        // 检测是否是WIFI
        if (info.getType() == ConnectivityManager.TYPE_WIFI)
            return "WiFi";

        // 如果不是移动网络
        if (info.getType() != ConnectivityManager.TYPE_MOBILE)
            return "Unknown";

        // 检测移动网络类型：2G、3G、4G
        TelephonyManager mTelephonyManager = (TelephonyManager)Cocos2dxActivity.getContext().getSystemService(Context.TELEPHONY_SERVICE);
        int networkType = mTelephonyManager.getNetworkType();

        switch (networkType) 
        {
            case TelephonyManager.NETWORK_TYPE_GPRS:
            case TelephonyManager.NETWORK_TYPE_EDGE:
            case TelephonyManager.NETWORK_TYPE_CDMA:
            case TelephonyManager.NETWORK_TYPE_1xRTT:
            case TelephonyManager.NETWORK_TYPE_IDEN:
                return "2G";

            case TelephonyManager.NETWORK_TYPE_UMTS:
            case TelephonyManager.NETWORK_TYPE_EVDO_0:
            case TelephonyManager.NETWORK_TYPE_EVDO_A:
            case TelephonyManager.NETWORK_TYPE_HSDPA:
            case TelephonyManager.NETWORK_TYPE_HSUPA:
            case TelephonyManager.NETWORK_TYPE_HSPA:
            case TelephonyManager.NETWORK_TYPE_EVDO_B:
            case TelephonyManager.NETWORK_TYPE_EHRPD:
            case TelephonyManager.NETWORK_TYPE_HSPAP:
                return "3G";

            case TelephonyManager.NETWORK_TYPE_LTE:
                return "4G";

            default:
                return "Unknown";
        }
    }

    /**
     * 打开浏览器
     * @param {String} url
     */
    public static void open_browser(String url) {
        // MX3上下面3段代码会造成按钮抖动很多次，类似小米Pad上点击微信按钮抖动
        Intent i = new Intent(Intent.ACTION_VIEW);
        i.setData(Uri.parse(url));
        Cocos2dxActivity.getContext().startActivity(i);
    }

    /**
     * User Agent
     */
    public static String browser_useragent() {
        try
        {
            if (GDeviceInfoAndroid._browser_useragent == "")
            {
                // 获取真正的UA，会有延迟，必须在主线程
                new Handler(Looper.getMainLooper()).post(new Runnable() {
                    public void run() {
                        try
                        {
                        	GDeviceInfoAndroid._browser_useragent = new WebView(Cocos2dxActivity.getContext()).getSettings().getUserAgentString();
                        }
                        catch (Exception e)
                        {
                        }
                    }
                });

                // 在没获取到真正UA前临时给一个值
                GDeviceInfoAndroid._browser_useragent = System.getProperty("http.agent");
            }

            return GDeviceInfoAndroid._browser_useragent != null ? GDeviceInfoAndroid._browser_useragent : "Null";
        }
        catch (Exception e)
        {
            return "Unknown";
        }
    }

    /**
     * 振动
     */
    public static void vibrate() {
        Vibrator v = (Vibrator)Cocos2dxActivity.getContext().getSystemService(Context.VIBRATOR_SERVICE);
        v.vibrate(400);
    }

    /**
     * 唤醒
     */
    public static void keep_awake(final boolean keep) {
        new Handler(Looper.getMainLooper()).post(new Runnable() {
            public void run() {
                if (keep)
                    ((Cocos2dxActivity)Cocos2dxActivity.getContext()).getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
                else
                    ((Cocos2dxActivity)Cocos2dxActivity.getContext()).getWindow().clearFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
            }
        });                
    }

    /**
     * 键盘
     */
    public static boolean keyboard_exist() {
        return ((Cocos2dxActivity)Cocos2dxActivity.getContext()).getWindow().getAttributes().softInputMode ==
        		WindowManager.LayoutParams.SOFT_INPUT_STATE_UNSPECIFIED;
    }

    public static void keyboard_close() {
        ((Cocos2dxActivity)Cocos2dxActivity.getContext()).getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_HIDDEN);
    }

    /**
     * 获取JS、PIShell、Resource的版本号
     */
    private static native int nativeVersionJS();
    private static native int nativeVersionResource();

    // members
    private static String _browser_useragent = "";
}
