#pragma once

#include "Identity.h"

namespace game
{
	class IPlayer;
	class ICoach;
	class IPerson;
	class ITeam;
	class IFinance;

	/**
	*	俱乐部
	*/
	class IClub : public Identity
	{
	public:
		virtual ~IClub() {}
	public:
		/**
		*	所在国家
		*/
		virtual int getCountryID() const = 0;
		/**
		*	俱乐部财政
		*/
		virtual const IFinance* getFinance() const = 0;
		/**
		*	雇佣
		*/
		virtual bool hireEmployee(IPerson* pPerson) const = 0;
		/**
		*	解雇
		*/
		virtual bool fireEmployee(IPerson* pPerson) const = 0;
		/**
		*	获取员工，根据编号
		*/
		virtual const IPerson* getEmployee(int nPersonID) const = 0;
		/**
		*	生成队伍
		*/
		virtual ITeam* generateTeam() const = 0;
		/**
		*	移除队伍
		*/
		virtual bool purgeTeam(ITeam* pTeam) const = 0;
		/**
		*	查找队伍
		*/
		virtual const ITeam* findTeam(int nTeamID) const = 0;
	};
}