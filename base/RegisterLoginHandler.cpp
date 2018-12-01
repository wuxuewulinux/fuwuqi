#include "RegisterLoginHandler.hpp"
#include "quanju.hpp"
#include "RegisterLoginWork.hpp"
#include "enterfunction.hpp"
#include "sendclient.hpp"

RegisterLoginHandler::RegisterLoginHandler()
{

}
RegisterLoginHandler::~RegisterLoginHandler()
{

}

int RegisterLoginHandler::OnCheckCSMsg(const CSMsg& rMsg, CSMsgID eMsgId)
{
	if ( !rMsg.has_head())
	{
		return -1;
	}
	const CSMsgHead& rHead= rMsg.head();
	if ( ! (rHead.has_uid()) || ! rHead.has_msgid())
	{
		return -2;
	}
	if ( (!rMsg.has_body()) )
	{
		return -3;
	}
	if (rHead.has_msgid() != CS_MSGID_RegisterLogin)
	{
		return -4;
	}
	const CSMsgBody& rBody = rMsg.body();
	const CSRegisterLoginReq& rTmp = rBody.registerloginreq();
	if ( !(rTmp.has_cmd()) || !(rTmp.has_reqparam()) )
	{
		return -5;
	}

	return 0;
	//���ϵĴ�����һ�����е��������Ͳ�һ���͸�һ�¾Ϳ����ˡ�
}



void* RegisterLoginHandler::OnCSMsg(CSMsg& rMsg, int Uid, CSMsgID eMsgId, int CmdType)
{
	CSMsgHead * pHead = rMsg.mutable_head();
	if (!pHead)
	{
		return NULL;
	}
	pHead->set_uid(Uid);
	pHead->set_msgid(eMsgId);
	CSMsgBody * pbody = rMsg.mutable_body();
	if (!pbody)
	{
		return NULL;
	}
	CSRegisterLoginReq * pReq = pbody->mutable_registerloginreq();
	if (!pReq)
	{
		return NULL;
	}
	CSRegisterLoginReqParam * pReqParam = pReq->mutable_reqparam();  //ע��ÿ��ģ��ֻҪ�жϵ��ò�νṹ��������ж��ˣ��Ϳ�ʼ���ж�Ӧָ���ж���
	if (!pReqParam)
	{
		return NULL;
	}
	//�����￪ʼ���ӽṹָ��Ϳ����ˡ�

	CSLoginReq * pLoginReq = pReqParam->mutable_loginreq();				//��ȡ��½�ṹָ���ڴ�
	CSRegisterReq * pRegisterReq = pReqParam->mutable_registerreq();	//��ȡע��ṹָ���ڴ�

	/////////////////////////

	//�����жϻ�ȡ��Ӧ���ڴ�ָ���ȥ
	if (CmdType == CSRegisterLoginCmd_Register)
	{
		return (void*)pRegisterReq;
	}
	else if (CmdType == CSRegisterLoginCmd_Login)
	{
		return (void*)pLoginReq;
	}
	////////
	return NULL;
}



int RegisterLoginHandler::OnServerMsg(const SSMsg& rSSMsg)
{


	return 0;
}


int RegisterLoginHandler::OnClientMsg(const CSMsg& rCSMsg, int iFd)
{

	int iRet = -1;
	iRet = OnCheckCSMsg(rCSMsg, CS_MSGID_RegisterLogin);
	if (iRet < 0)
	{
		//��־���
		printf("RegisterLoginHandler CheckCSMsg : %d",iRet);
		log.sprintf(BUFF,"RegisterLoginHandler CheckCSMsg : %d",iRet);
		return -1;
	}
	/*
	����Ĵ���ÿ��ģ���Handler���OnClientMsg������һ��
	*/
	const CSRegisterLoginReq &req = rCSMsg.body().registerloginreq();
	switch (req.cmd())
	{
	case CSRegisterLoginCmd_Register:					//ע�Ṧ��
		{
			iRet = OnRegisterReq(rCSMsg, iFd);
		}
		break;
	case CSRegisterLoginCmd_Login:						//��½����
		{
			iRet = OnLoginReq(rCSMsg, iFd);
		}
		break;
	default:
		iRet = -1;
	}
	if (iRet < 0)
	{
		//�жϹ����߼��Ƿ���ȷ�������ܻ���ָ��������ָ�����ԭ�������ָ��Ϊ�գ��������ݷ�������
		printf("RegisterLoginHandler error : %d",iRet);
		log.sprintf(BUFF,"RegisterLoginHandler error : %d",iRet);
	}
	/*
	�������ݷ����ı�ʱ�ͱ���������ݿ⣬�����ε���������ݿ���Ҫ���¾���������ģʽȥ��д
	if ( req.cmd() == CSCardCmd_SaveDeck ||  req.cmd() == CSCardCmd_UpHeroLv ||
		req.cmd() == CSCardCmd_UpHeroStar ||  req.cmd() == CSCardCmd_UpMagicLv ||
		req.cmd() == CSCardCmd_SetUsingDeck || req.cmd() == CSCardCmd_CrystalDraw ||
		req.cmd() == CSCardCmd_UpRuneStep || req.cmd() == CSCardCmd_UpRuneAdvance || 
		req.cmd() == CSCardCmd_UpStep || req.cmd() == CSCardCmd_SaveTalentAttr)
	{
		if ( 0 == iRet )
		{
			CRoleObj * pRoleObj = CMemPoolMgr::GetRoleObjPool().GetByKey( rCSMsg.head().uid() );
			LOG_ASSERT_RET_INT( pRoleObj, -1 );
			CSnapHandler::UpdateSnap(pRoleObj);
		}

	}
	*/
	return 0;
}



int RegisterLoginHandler::OnRegisterReq(const CSMsg& rCSMsg, int iFd)
{
	const CSRegisterReq & rRegisterReq = rCSMsg.body().registerloginreq().reqparam().registerreq();
	CSMsg oCSMsg;
	//��ȡҪ���ͻ��˵������ڴ��ַ
	CSRegisterRsp* pRegisterRsp = static_cast<CSRegisterRsp*>(OnCSMsg(oCSMsg, rCSMsg.head().uid(), CS_MSGID_RegisterLogin, CSRegisterLoginCmd_Register)); 
	HANDCHECH_P(pRegisterRsp,-1);
	//��ȡ�ÿͻ��˵�Role��
	CRoleObj* pRoleObj = GetRole(rCSMsg.head().uid());
	HANDCHECH_P(pRoleObj,-2);
	//��ʼִ�й����߼�
	int iRet = RegisterLoginWork::Register(pRoleObj,rRegisterReq,pRegisterRsp);
	//�����С��0֤�����ݴ��󣬲����Է���,������־��
	if (iRet < 0)
	{
		printf("RegisterLoginWork Register error : %d",iRet);
		log.sprintf(BUFF,"RegisterLoginWork Register error : %d",iRet);
		return -3;
	}
	//��ʼ�������ݸ��ͻ���
	SendClient(iFd,&oCSMsg);
	return 0;
}


int RegisterLoginHandler::OnLoginReq(const CSMsg& rCSMsg, int iFd)
{
	const CSLoginReq & rLoginReq = rCSMsg.body().registerloginreq().reqparam().loginreq();

	CSMsg oCSMsg;
	CSLoginRsp* pLoginRsp = static_cast<CSLoginRsp*>(OnCSMsg(oCSMsg, rCSMsg.head().uid(), CS_MSGID_RegisterLogin, CSRegisterLoginCmd_Login)); 
	HANDCHECH_P(pLoginRsp,-1);
	CRoleObj* pRoleObj = GetRole(rCSMsg.head().uid());
	HANDCHECH_P(pRoleObj,-2);

	int iRet = RegisterLoginWork::Login(pRoleObj,rLoginReq,pLoginRsp);
	
	if (iRet < 0)
	{
		printf("RegisterLoginWork  Login error : %d",iRet);
		log.sprintf(BUFF,"RegisterLoginWork Login error : %d",iRet);
		return -3;
	}
	SendClient(iFd,&oCSMsg);
	return 0;
}