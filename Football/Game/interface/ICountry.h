#pragma once

#include "Identity.h"

namespace game
{
	class ILeague;
	class IClub;
	/**
	*	国家
	*/
	class ICountry
	{
	public:
		virtual ~ICountry() {}
	public:
		/**
		*	生成联赛
		*/
		virtual ILeague* generateLeague() const = 0;
		/**
		*	移除联赛
		*/
		virtual bool purgeLeague(ILeague* pLeague) const = 0;
		/**
		*	查找联赛
		*/
		virtual ILeague* findLeague(int nLeagueID) const = 0;
		/**
		*	生成俱乐部
		*/
		virtual IClub* generateClub() const = 0;
		/**
		*	移除俱乐部
		*/
		virtual bool purgeClub(IClub* pClub) const = 0;
		/**
		*	查找俱乐部
		*/
		virtual IClub* findClub(int nClubID) const = 0;
	};
}