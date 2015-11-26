//
//  GDeviceInfoIOS.cpp
//  libguang
//
//  Created by ChunGuang Yan on 15/11/26.
//  Copyright © 2015年 guang. All rights reserved.
//

#include "GDeviceInfoIOS.h"
#include <mach/mach.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreTelephony/CTCarrier.h>
#import <AudioToolbox/AudioServices.h>
#import <UIKit/UIKit.h>

USING_NS_CC;

static GDeviceInfoIOS* _instanceGDeviceInfoIOS = nullptr;

GDeviceInfoIOS* GDeviceInfoIOS::getInstance()
{
    if(!_instanceGDeviceInfoIOS)
    {
        _instanceGDeviceInfoIOS = new GDeviceInfoIOS();
    }
    return _instanceGDeviceInfoIOS;
}

unsigned int GDeviceInfoIOS::memory_used()
{
    struct task_basic_info info = {0};
    mach_msg_type_number_t size = sizeof(info);
    kern_return_t          kerr = task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&info, &size);
    
    return (kerr == KERN_SUCCESS) ? (unsigned int)info.resident_size : 0; // size in bytes
}

unsigned int GDeviceInfoIOS::memory_free()
{
    mach_port_t            host_port = mach_host_self();
    mach_msg_type_number_t host_size = sizeof(vm_statistics_data_t) / sizeof(integer_t);
    
    vm_size_t pagesize = 0;
    vm_statistics_data_t vm_stat = {0};
    
    host_page_size(host_port, &pagesize);
    host_statistics(host_port, HOST_VM_INFO, (host_info_t)&vm_stat, &host_size);
    
    return (unsigned int)(vm_stat.free_count * pagesize);
}

std::string GDeviceInfoIOS::getSDPath()
{
    return "";
}

bool GDeviceInfoIOS::isSDEnable()
{
    return false;
}

float GDeviceInfoIOS::cpu_usage()
{
    kern_return_t kr;
    task_info_data_t tinfo;
    mach_msg_type_number_t task_info_count;
    
    task_info_count = TASK_INFO_MAX;
    kr = task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)tinfo, &task_info_count);
    if (kr != KERN_SUCCESS)
        return 0;
    
    task_basic_info_t      basic_info;
    thread_array_t         thread_list;
    mach_msg_type_number_t thread_count;
    
    thread_info_data_t     thinfo;
    mach_msg_type_number_t thread_info_count;
    
    thread_basic_info_t basic_info_th;
    uint32_t stat_thread = 0; // Mach threads
    
    basic_info = (task_basic_info_t)tinfo;
    
    // get threads in the task
    kr = task_threads(mach_task_self(), &thread_list, &thread_count);
    
    if (kr != KERN_SUCCESS)
        return 0;
    
    if (thread_count > 0)
        stat_thread += thread_count;
    
    long tot_sec  = 0;
    long tot_usec = 0;
    float tot_cpu = 0;
    
    for (int j = 0; j < thread_count; j++)
    {
        thread_info_count = THREAD_INFO_MAX;
        kr = thread_info(thread_list[j], THREAD_BASIC_INFO,
                         (thread_info_t)thinfo, &thread_info_count);
        
        if (kr != KERN_SUCCESS)
            return 0;
        
        basic_info_th = (thread_basic_info_t)thinfo;
        
        if (!(basic_info_th->flags & TH_FLAGS_IDLE))
        {
            tot_sec  = tot_sec + basic_info_th->user_time.seconds + basic_info_th->system_time.seconds;
            tot_usec = tot_usec + basic_info_th->system_time.microseconds + basic_info_th->system_time.microseconds;
            tot_cpu  = tot_cpu + basic_info_th->cpu_usage / (float)TH_USAGE_SCALE * 100.0;
        }
        
    } // for each thread
    
    kr = vm_deallocate(mach_task_self(), (vm_offset_t)thread_list, thread_count * sizeof(thread_t));
    assert(kr == KERN_SUCCESS);
    
    return tot_cpu;
}

std::string GDeviceInfoIOS::device_telecom()
{
    CTTelephonyNetworkInfo *info = [[CTTelephonyNetworkInfo alloc] init];
    CTCarrier           *carrier = [info subscriberCellularProvider];
    
    std::string telecom(carrier && [carrier carrierName] ? [[carrier carrierName] UTF8String] : "");
    
    [info release];
    
    return telecom;
}

std::string GDeviceInfoIOS::device_hardware()
{
    return [[[UIDevice currentDevice] model] UTF8String];
}

std::string GDeviceInfoIOS::device_network()
{
    if ([[[UIDevice currentDevice] systemVersion] intValue] >= 7)
    {
        CTTelephonyNetworkInfo *info = [[CTTelephonyNetworkInfo alloc] init];
        static NSDictionary    *map  = [[NSDictionary alloc] initWithObjectsAndKeys:
                                        @"2G", CTRadioAccessTechnologyGPRS,
                                        @"2G", CTRadioAccessTechnologyEdge,
                                        
                                        @"3G", CTRadioAccessTechnologyWCDMA,
                                        @"3G", CTRadioAccessTechnologyHSDPA,
                                        @"3G", CTRadioAccessTechnologyHSUPA,
                                        @"3G", CTRadioAccessTechnologyCDMA1x,
                                        @"3G", CTRadioAccessTechnologyCDMAEVDORev0,
                                        @"3G", CTRadioAccessTechnologyCDMAEVDORevA,
                                        @"3G", CTRadioAccessTechnologyCDMAEVDORevB,
                                        @"3G", CTRadioAccessTechnologyeHRPD,
                                        
                                        @"4G", CTRadioAccessTechnologyLTE,
                                        nil];
        
        NSString *key = info.currentRadioAccessTechnology;
        NSString *val = key ? [map objectForKey:key] : @"Unknown";
        
        [info release];
        
        return [val UTF8String];
    }
    
    return "Unknown";
}

void GDeviceInfoIOS::open_browser(const std::string &url)
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithUTF8String:url.c_str()]]];
}

std::string GDeviceInfoIOS::browser_useragent()
{
    static std::string agent;
    
    if (agent.empty())
    {
        UIWebView *web = [[UIWebView alloc] initWithFrame:CGRectZero];
        NSString  *val = [web stringByEvaluatingJavaScriptFromString:@"navigator.userAgent"];
        
        agent = val ? [val UTF8String] : "";
        
        [web release];
    }
    
    return agent;
}

void GDeviceInfoIOS::vibrate()
{
    AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
}

void GDeviceInfoIOS::keep_awake(bool keep)
{
    [[UIApplication sharedApplication] setIdleTimerDisabled:keep ? YES : NO];
}

bool GDeviceInfoIOS::keyboard_exist()
{
    UIView *view = (UIView*)Director::getInstance()->getOpenGLView()->getEAGLView();
    NSArray *subviews = view.subviews;
    
    for (UIView* view in subviews)
    {
        if([view isKindOfClass:NSClassFromString(@"UITextField")] ||
           [view isKindOfClass:NSClassFromString(@"UITextView")])
        {
            if ([view isFirstResponder])
            {
                return true;
            }
        }
    }
    
    return false;
}

void GDeviceInfoIOS::keyboard_close()
{
    UIView *view = (UIView*)Director::getInstance()->getOpenGLView()->getEAGLView();
    NSArray *subviews = view.subviews;
    
    for (UIView* view in subviews)
    {
        if([view isKindOfClass:NSClassFromString(@"UITextField")] ||
           [view isKindOfClass:NSClassFromString(@"UITextView")])
        {
            if ([view isFirstResponder])
            {
                [view resignFirstResponder];
            }
        }
    }
}