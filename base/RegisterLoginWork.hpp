
#include "RoleObj.hpp"
#include "../proto/CSmsg.pb.h"

class RegisterLoginWork
{

public:

	//ÿ��ģ�鶼������Work�࣬������ִ��ģ�鹦�ܵ��߼�

	static int Register(CRoleObj* pRole,const CSRegisterReq& rReq,CSRegisterRsp* pRsp);

	static int Login(CRoleObj* pRole,const CSLoginReq& rReq,CSLoginRsp* pRsp);

private: 

};