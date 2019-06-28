#pragma once

#include "../base/Component.h"
#include <map>
#include <cstdint>

namespace game
{
	/**
	*	比赛队伍
	*/
	class Team : public Component
	{
	public:
		Team();
		virtual ~Team();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Team);

		/**
		*	所属俱乐部
		*/
		CREATE_COMPONENT_PROPERTY(uint64_t, ClubID);
		/**
		*	所属联赛
		*/
		CREATE_COMPONENT_PROPERTY(uint64_t, LeagueID);
	};
}