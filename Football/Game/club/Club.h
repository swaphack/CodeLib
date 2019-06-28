#pragma once

#include <cstdint>

#include "../base/Component.h"
#include "../enum/eProperty.h"
#include "../finance/Finance.h"

namespace game
{
	/**
	*	���ֲ�
	*/
	class Club : public Component
	{
	public:
		Club();
		virtual ~Club();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Club);
	public:
		/**
		*	���ڹ���
		*/
		CREATE_COMPONENT_PROPERTY(uint64_t, Country);
		/**
		*	���ֲ�����
		*/
		CREATE_COMPONENT_FUNCTION(Finance, Finance);
	protected:
		 
	};
}