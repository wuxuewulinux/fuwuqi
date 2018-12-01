


#ifndef _REGISTERLOGINHANDLER_HPP_
#define _REGISTERLOGINHANDLER_HPP_

#include "Handler.hpp"
#include "../proto/CSmsg.pb.h"
#include "../proto/SSmsg.pb.h"

class RegisterLoginHandler : public IHandler
{
public:
	RegisterLoginHandler();
	virtual ~RegisterLoginHandler();

	virtual int OnClientMsg(const CSMsg& rCSMsg, int iFd); //iFd为io套接字
	virtual int OnServerMsg(const SSMsg& rSSMsg);

private:
	//返回一个结构内存地址出来。eMsgId为第一层协议号，CmdType为第2层协议号，pMsgObj传入一个结构的空地址，函数会给该空地址附上值
	//该函数每个模块的handler都会有这个函数，每个模块有自己该函数的封装

	void* OnCSMsg(CSMsg& rMsg, int Uid, CSMsgID eMsgId, int CmdType);  

	//检查客户端的数据包是否存在，正确就返回0，不正确就返回负数
	int OnCheckCSMsg(const CSMsg& rMsg, CSMsgID eMsgId);

	// 注: OnCSMsg 和 OnCheckCSMsg 和 OnClientMsg 这三个函数每个模块的Handler都有自个的封装。必须要有的


	//下面是所有模块功能的入口

	int OnRegisterReq(const CSMsg& rCSMsg, int iFd);							//注册功能
	int OnLoginReq(const CSMsg& rCSMsg, int iFd);								//登陆功能

};


#endif // !_REGISTERLOGINHANDLER_HPP_
