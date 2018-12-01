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
	//以上的代码差不多一样，有的数据类型不一样就改一下就可以了。
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
	CSRegisterLoginReqParam * pReqParam = pReq->mutable_reqparam();  //注：每个模块只要判断到该层次结构就算结束判断了，就开始进行对应指针判断了
	if (!pReqParam)
	{
		return NULL;
	}
	//从这里开始增加结构指针就可以了。

	CSLoginReq * pLoginReq = pReqParam->mutable_loginreq();				//获取登陆结构指针内存
	CSRegisterReq * pRegisterReq = pReqParam->mutable_registerreq();	//获取注册结构指针内存

	/////////////////////////

	//进行判断获取对应的内存指针出去
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
		//日志输出
		printf("RegisterLoginHandler CheckCSMsg : %d",iRet);
		log.sprintf(BUFF,"RegisterLoginHandler CheckCSMsg : %d",iRet);
		return -1;
	}
	/*
	上面的代码每个模块的Handler类的OnClientMsg函数都一样
	*/
	const CSRegisterLoginReq &req = rCSMsg.body().registerloginreq();
	switch (req.cmd())
	{
	case CSRegisterLoginCmd_Register:					//注册功能
		{
			iRet = OnRegisterReq(rCSMsg, iFd);
		}
		break;
	case CSRegisterLoginCmd_Login:						//登陆功能
		{
			iRet = OnLoginReq(rCSMsg, iFd);
		}
		break;
	default:
		iRet = -1;
	}
	if (iRet < 0)
	{
		//判断功能逻辑是否正确，不可能会出现负数，出现负数的原因可能是指针为空，或者数据发生错误
		printf("RegisterLoginHandler error : %d",iRet);
		log.sprintf(BUFF,"RegisterLoginHandler error : %d",iRet);
	}
	/*
	等有数据发生改变时就必须更新数据库，想屏蔽掉，如果数据库需要更新就照这样的模式去书写
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
	//获取要给客户端的数据内存地址
	CSRegisterRsp* pRegisterRsp = static_cast<CSRegisterRsp*>(OnCSMsg(oCSMsg, rCSMsg.head().uid(), CS_MSGID_RegisterLogin, CSRegisterLoginCmd_Register)); 
	HANDCHECH_P(pRegisterRsp,-1);
	//获取该客户端的Role类
	CRoleObj* pRoleObj = GetRole(rCSMsg.head().uid());
	HANDCHECH_P(pRoleObj,-2);
	//开始执行功能逻辑
	int iRet = RegisterLoginWork::Register(pRoleObj,rRegisterReq,pRegisterRsp);
	//如果是小于0证明数据错误，不可以发送,输入日志里
	if (iRet < 0)
	{
		printf("RegisterLoginWork Register error : %d",iRet);
		log.sprintf(BUFF,"RegisterLoginWork Register error : %d",iRet);
		return -3;
	}
	//开始发送数据给客户端
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