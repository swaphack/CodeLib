#pragma once

#include "../base/Component.h"
#include <cstdint>

namespace game
{
	/**
	*	联赛
	*/
	class League : public Component
	{
	public:
		League();
		virtual ~League();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(League);
		/**
		*	联赛等级
		*/
		CREATE_COMPONENT_PROPERTY(uint8_t, Level);
		/**
		*	参加队伍数
		*/
		int count() const;
		/**
		*	获取队伍
		*/
		const ITeam* getTeam(int nID) const;
		/**
		*	添加队伍
		*/
		void addTeam(ITeam* pTeam);
		/**
		*	移除队伍
		*/
		void removeTeam(int nID);
	};
}