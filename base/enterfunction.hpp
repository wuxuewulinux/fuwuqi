#ifndef _ENTERFUNCTION_HPP_
#define _ENTERFUNCTION_HPP_

#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include "quanju.hpp"

void gateway();         //������������

bool LogInit(std::string path);       //����������־�ļ�

CRoleObj * GetRole(int Uid);

void PushRole(int Uid,CRoleObj* rRole);

#endif // !_ENTERFUNCTION_HPP_
