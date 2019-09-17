//
// Created by Curie on 2019/9/17.
//

#ifndef APPTOOLS_SHELL_H
#define APPTOOLS_SHELL_H
#include <cstdlib>
#include <string>
#include <cstdio>
#include "log.h"
namespace Shell{
    const char * TAG = "Shell";
    const unsigned RESULT_OK = 0;
    bool exec(const char * script){
        return system(script) == RESULT_OK;
    }
    char * execWith(const char * script){
        if(script == nullptr){
            Log::e(TAG,"script is null");
            return nullptr;
        }
        string result;
        FILE * file;
        const int max_buffer_size = 256*2;
        char buffer[max_buffer_size];
        file = popen(script,"r");
        if(file){
            while(!feof(file)){
                if(fgets(buffer,max_buffer_size,file) != nullptr){
                    result.append(buffer);
                }
            }
            pclose(file);
            return const_cast<char *>(result.c_str());
        } else{
            Log::e(TAG,"can not exec script");
        }
        return nullptr;
    }
}
#endif //APPTOOLS_SHELL_H
