
#ifndef _DATASTORE_HPP_
#define _DATASTORE_HPP_

#include "../proto/DBmsg.pb.h"

//role��ģ�鲻��Ҫ�����ṹ��

//��������ģ������ݽṹ����Ҫ�����������һ���ṹ��������.ÿ���ṹ�嶼��Ӧһ��DBmsg�ļ��Ľṹ

//DBmsg�ļ��Ľṹ�������ýṹ��ST2PB��PB2ST�����ĺ���������ÿ�������Ľṹ������Ҫ��ST2PB������PB2ST����

//ST2PB��ʾ�����ݴ浽���ݿ�Ĳ�����PB2ST��ʾ�����ݿ�ȡ���ݳ���

/*
typedef struct tagDBTreasureInfo  //�ýṹ�屣����ģ������
{
TDBTreasureList m_stTreasureList; // TreasureList
uint32_t m_uiLastFreeTime; // LastFreeTime
uint32_t m_uiLastAstrologyTime; // LastAstrologyTime
uint32_t m_uiDailyAstrologyTimes; // DailyAstrologyTimes
uint32_t m_uiTotalAstrologyTimes; // TotalAstrologyTimes
uint8_t m_ucHadDrop200; // HadDrop200

int ST2PB(DBTreasureInfo& msg);            
int PB2ST(const DBTreasureInfo& msg);
} TDBTreasureInfo;
*/



#endif // !_DATASTORE_HPP_
