#ifndef _ENTERFUNCTION_HPP_
#define _ENTERFUNCTION_HPP_

#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include "../proto/msg.pb.h"


void gateway();         //启动服务器。   

//worksend和timesend和errorsend函数是上层逻辑必须调用的接口

void worksend(int userio,MY::msg * test);    //该函数是逻辑层在发送数据给客户端时，必须调用该接口才能发送数据出去。

void timesend(int kaiguan,int index,int miao,int userid); //该函数是逻辑层只要用到定时器就会调用，给上层一个定时接口

void errorsend(int userio,int error);           //发送错误码给客户端，只要出现错误提示给客户端就调用该函数接口。error为错误码的值

bool LogInit(std::string path);       //启动所有日志文件


#endif // !_ENTERFUNCTION_HPP_
