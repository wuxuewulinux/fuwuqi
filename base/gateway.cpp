

#include"quanju.hpp"
#include"logicconfigmanager.hpp"
#include "lognamespace.hpp"
#include "enterfunction.hpp"
#include "socketku.hpp"
#include "pthreadstart.hpp"

void gateway()
{
int litenfd;
//初始化游戏模块 日志
if(!LogInit("/home/wuxuewu/fuwuqi/"))
{
return;
}
//初始化记录错误信息的日志
if(!log.Init("/home/wuxuewu/fuwuqi/log/error.txt"))
{
std::cout<<"error log create fail !"<<std::endl;
return;
}
//启动所有线程（读 写 处理工作 定时器 这四个线程）
if(pthreadstart() < 0)
 return;

//开始读取游戏配置
if(!LOGIC_CONFIG->Init("/home/wuxuewu/fuwuqi/config_xml/"))
	return;
const struct my_server * test = LOGIC_CONFIG->GetServerMysqlConfig().GetServerConfig(); //获取IP和端口
// TCP/IP启动
Socket_Ku socket_lei(test->ip.c_str(),test->port);
if(socket_lei.socket_creat() < 0)
	return;
if(socket_lei.socket_setsockopt() < 0)
	return;
if(socket_lei.socket_bind() < 0)
	return;
if(socket_lei.socket_listen() < 0)
	return;
litenfd=socket_lei.socket_listcnfd();   //获取服务器监听IO
//epoll模型启动
epoll_lei.Epoll_Creat();
epoll_lei.Epoll_Add(litenfd);

while(1)
{
 epoll_lei.Epoll_Wait(&socket_lei);   //epoll检测IO事件

}

return;

}
