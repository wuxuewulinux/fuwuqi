
#ifndef _ROLEOBJ_HPP_
#define _ROLEOBJ_HPP_

#include "../proto/CSmsg.pb.h"
#include "../proto/DBmsg.pb.h"


class CRoleObj
{
public:
	CRoleObj(){}
	~CRoleObj(){}

	
	int Init();			//��ʼ������ģ������
	void SetFd(int iFd) { m_iFd = iFd; }
	int GetFd() { return m_iFd; }
	int SetRoleInfo(const DBRoleInfo& rRoleinfo);			//�����ݿ��õ�role�ṹȻ�������ģ�鿪ʼ��ֵ
	int GenDBRoleInfo(DBRoleInfo* pRoleinfo);				//�Ѹ���ģ�����ֵ���õ�role�ṹ�У��������ݿ�洢

private:

	int m_iFd;		//�׽���IO	


	//��Ӹ���ģ��������������

};

#endif