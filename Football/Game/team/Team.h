#pragma once

#include "../base/Component.h"
#include <map>
#include <cstdint>

namespace game
{
	/**
	*	��������
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
		*	�������ֲ�
		*/
		CREATE_COMPONENT_PROPERTY(uint64_t, ClubID);
		/**
		*	��������
		*/
		CREATE_COMPONENT_PROPERTY(uint64_t, LeagueID);
	};
}