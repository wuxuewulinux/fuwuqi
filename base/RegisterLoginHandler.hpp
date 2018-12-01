


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

	virtual int OnClientMsg(const CSMsg& rCSMsg, int iFd); //iFdΪio�׽���
	virtual int OnServerMsg(const SSMsg& rSSMsg);

private:
	//����һ���ṹ�ڴ��ַ������eMsgIdΪ��һ��Э��ţ�CmdTypeΪ��2��Э��ţ�pMsgObj����һ���ṹ�Ŀյ�ַ����������ÿյ�ַ����ֵ
	//�ú���ÿ��ģ���handler���������������ÿ��ģ�����Լ��ú����ķ�װ

	void* OnCSMsg(CSMsg& rMsg, int Uid, CSMsgID eMsgId, int CmdType);  

	//���ͻ��˵����ݰ��Ƿ���ڣ���ȷ�ͷ���0������ȷ�ͷ��ظ���
	int OnCheckCSMsg(const CSMsg& rMsg, CSMsgID eMsgId);

	// ע: OnCSMsg �� OnCheckCSMsg �� OnClientMsg ����������ÿ��ģ���Handler�����Ը��ķ�װ������Ҫ�е�


	//����������ģ�鹦�ܵ����

	int OnRegisterReq(const CSMsg& rCSMsg, int iFd);							//ע�Ṧ��
	int OnLoginReq(const CSMsg& rCSMsg, int iFd);								//��½����

};


#endif // !_REGISTERLOGINHANDLER_HPP_
