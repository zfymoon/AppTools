//
// Created by Curie on 2019/9/17.
//

#ifndef APPTOOLS_LOG_H
#define APPTOOLS_LOG_H
#include <iostream>
using namespace std;
class Log{
public:
    static void d(const char * tag,const char * para){
        cout<<"["<<tag<<"] "<<para;
    }
    static void e(const char * tag,const char * para){
        cerr<<"["<<tag<<"] "<<para;
    }
};

#endif //APPTOOLS_LOG_H
