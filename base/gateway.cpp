

#include"quanju.hpp"
#include"logicconfigmanager.hpp"
#include "lognamespace.hpp"
#include "enterfunction.hpp"
#include "socketku.hpp"
#include "pthreadstart.hpp"

void gateway()
{
int litenfd;
//��ʼ����Ϸģ�� ��־
if(!LogInit("/home/wuxuewu/fuwuqi/"))
{
return;
}
//��ʼ����¼������Ϣ����־
if(!log.Init("/home/wuxuewu/fuwuqi/log/error.txt"))
{
std::cout<<"error log create fail !"<<std::endl;
return;
}
//���������̣߳��� д ������ ��ʱ�� ���ĸ��̣߳�
if(pthreadstart() < 0)
 return;

//��ʼ��ȡ��Ϸ����
if(!LOGIC_CONFIG->Init("/home/wuxuewu/fuwuqi/config_xml/"))
	return;
const struct my_server * test = LOGIC_CONFIG->GetServerMysqlConfig().GetServerConfig(); //��ȡIP�Ͷ˿�
// TCP/IP����
Socket_Ku socket_lei(test->ip.c_str(),test->port);
if(socket_lei.socket_creat() < 0)
	return;
if(socket_lei.socket_setsockopt() < 0)
	return;
if(socket_lei.socket_bind() < 0)
	return;
if(socket_lei.socket_listen() < 0)
	return;
litenfd=socket_lei.socket_listcnfd();   //��ȡ����������IO
//epollģ������
epoll_lei.Epoll_Creat();
epoll_lei.Epoll_Add(litenfd);

while(1)
{
 epoll_lei.Epoll_Wait(&socket_lei);   //epoll���IO�¼�

}

return;

}
