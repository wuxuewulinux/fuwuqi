
#ifndef _ROLEOBJ_HPP_
#define _ROLEOBJ_HPP_

#include "../proto/CSmsg.pb.h"
#include "../proto/DBmsg.pb.h"


class CRoleObj
{
public:
	CRoleObj(){}
	~CRoleObj(){}

	
	int Init();			//初始化所有模块数据
	void SetFd(int iFd) { m_iFd = iFd; }
	int GetFd() { return m_iFd; }
	int SetRoleInfo(const DBRoleInfo& rRoleinfo);			//从数据库拿到role结构然后给各个模块开始设值
	int GenDBRoleInfo(DBRoleInfo* pRoleinfo);				//把各个模块的数值设置到role结构中，发给数据库存储

private:

	int m_iFd;		//套接字IO	


	//添加各个模块的类对象在这里

};

#endif