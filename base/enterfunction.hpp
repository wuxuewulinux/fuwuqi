#ifndef _ENTERFUNCTION_HPP_
#define _ENTERFUNCTION_HPP_

#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include "../proto/msg.pb.h"


void gateway();         //������������   

//worksend��timesend��errorsend�������ϲ��߼�������õĽӿ�

void worksend(int userio,MY::msg * test);    //�ú������߼����ڷ������ݸ��ͻ���ʱ��������øýӿڲ��ܷ������ݳ�ȥ��

void timesend(int kaiguan,int index,int miao,int userid); //�ú������߼���ֻҪ�õ���ʱ���ͻ���ã����ϲ�һ����ʱ�ӿ�

void errorsend(int userio,int error);           //���ʹ�������ͻ��ˣ�ֻҪ���ִ�����ʾ���ͻ��˾͵��øú����ӿڡ�errorΪ�������ֵ

bool LogInit(std::string path);       //����������־�ļ�


#endif // !_ENTERFUNCTION_HPP_
