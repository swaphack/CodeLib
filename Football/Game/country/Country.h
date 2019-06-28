#pragma once

#include "../base/Identity.h"
#include "../base/Component.h"

namespace game
{
	/**
	*	国家
	*/
	class Country : public Component
	{
	public:
		virtual ~Country() {}
	public:
		/**
		*	名称
		*/
		CREATE_COMPONENT_PROPERTY(std::string, Name);
		/**
		*	生成联赛
		*/
		League* generateLeague() const;
		/**
		*	移除联赛
		*/
		bool purgeLeague(League* pLeague) const;
		/**
		*	查找联赛
		*/
		League* findLeague(uint64_t nLeagueID) const;
		/**
		*	生成俱乐部
		*/
		Club* generateClub() const;
		/**
		*	移除俱乐部
		*/
		bool purgeClub(Club* pClub) const;
		/**
		*	查找俱乐部
		*/
		Club* findClub(uint64_t nClubID) const;
	};
}