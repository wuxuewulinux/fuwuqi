
#ifndef _DATASTORE_HPP_
#define _DATASTORE_HPP_

#include "../proto/DBmsg.pb.h"

//role类模块不需要声明结构体

//声明所有模块的数据结构，需要保存的数据用一个结构体来声明.每个结构体都对应一个DBmsg文件的结构

//DBmsg文件的结构都是做该结构体ST2PB和PB2ST函数的函数参数，每个声明的结构都必须要有ST2PB函数和PB2ST函数

//ST2PB表示把数据存到数据库的操作，PB2ST表示从数据库取数据出来

/*
typedef struct tagDBTreasureInfo  //该结构体保存在模块类中
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
