
#include "enterfunction.hpp"

CRoleObj * GetRole(int Uid)
{
	std::map<int, CRoleObj>::iterator iter = mRoleList.find(Uid);
	if (mRoleList.end() != iter)
	{
		return &iter->second;
	}	

	return  NULL;
}

void PushRole(int Uid,CRoleObj* rRole)
{
	if (rRole)
	{
		mRoleList[Uid] = *rRole;
	}

	return;
}