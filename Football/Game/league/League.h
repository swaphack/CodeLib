#pragma once

#include "../base/Component.h"
#include <cstdint>

namespace game
{
	/**
	*	����
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
		*	�����ȼ�
		*/
		CREATE_COMPONENT_PROPERTY(uint8_t, Level);
	};
}