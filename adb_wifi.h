//
// Created by Curie on 2019/9/17.
// adb 连接wifi

#ifndef APPTOOLS_ADB_WIFI_H
#define APPTOOLS_ADB_WIFI_H

#include <regex>
#include "shell.h"

const char * PORT = "9998";
const char * TAG = "adb_wifi";
/**
 * 简单连接adb到wifi
 */
void connect_wifi(){
    if(Shell::exec("adb --version")){
        auto adb_ifconfig = Shell::execWith("adb shell ifconfig");
        if(adb_ifconfig != nullptr){
            string pattern{R"(wlan0[\s\S]+inet addr:(\d{1,3}.\d{1,3}.\d{1,3}.\d{1,3}))"};
            string target(adb_ifconfig);
            smatch result;
            regex r(pattern);
            regex_search(target,result,r);
            if(!result.empty()){
                const char * ip_str = result.str(1).c_str();
                string connect_script = "adb tcpip ";
                connect_script += PORT;
                connect_script += ";adb  connect ";
                connect_script += ip_str;
                connect_script += ":";
                connect_script += PORT;
                Shell::exec(connect_script.c_str());
            }
        } else{
            Log::e(TAG,"No ifconfig");
        }
    } else{
        Log::e(TAG,"No adb.");
    }
}
#endif //APPTOOLS_ADB_WIFI_H
