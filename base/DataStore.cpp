
#include "DataStore.hpp"


//定义所有模块结构体的PB2ST 和 ST2PB函数
/*
int tagDBTreasureInfo::ST2PB(DBTreasureInfo& msg)
{
	DBTreasureList* treasurelist = msg.mutable_treasurelist();
	m_stTreasureList.ST2PB(*treasurelist);
	msg.set_lastfreetime(m_uiLastFreeTime);
	msg.set_lastastrologytime(m_uiLastAstrologyTime);
	msg.set_dailyastrologytimes(m_uiDailyAstrologyTimes);
	msg.set_totalastrologytimes(m_uiTotalAstrologyTimes);
	msg.set_haddrop200(m_ucHadDrop200);
	return 0;
}

int tagDBTreasureInfo::PB2ST(const DBTreasureInfo& msg)
{
	m_stTreasureList.PB2ST(msg.treasurelist());
	if (msg.has_lastfreetime())
	{
		m_uiLastFreeTime = msg.lastfreetime();
	}
	if (msg.has_lastastrologytime())
	{
		m_uiLastAstrologyTime = msg.lastastrologytime();
	}
	if (msg.has_dailyastrologytimes())
	{
		m_uiDailyAstrologyTimes = msg.dailyastrologytimes();
	}
	if (msg.has_totalastrologytimes())
	{
		m_uiTotalAstrologyTimes = msg.totalastrologytimes();
	}
	if (msg.has_haddrop200())
	{
		m_ucHadDrop200 = msg.haddrop200();
	}
	return 0;
}

*/