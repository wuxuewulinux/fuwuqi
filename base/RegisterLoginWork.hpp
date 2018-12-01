
#include "RoleObj.hpp"
#include "../proto/CSmsg.pb.h"

class RegisterLoginWork
{

public:

	//每个模块都有他的Work类，该类是执行模块功能的逻辑

	static int Register(CRoleObj* pRole,const CSRegisterReq& rReq,CSRegisterRsp* pRsp);

	static int Login(CRoleObj* pRole,const CSLoginReq& rReq,CSLoginRsp* pRsp);

private: 

};