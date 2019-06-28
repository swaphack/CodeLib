#pragma once

#include <cstdint>

#include "../base/Component.h"
#include "../enum/eProperty.h"
#include "../finance/Finance.h"

namespace game
{
	/**
	*	俱乐部
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
		*	所在国家
		*/
		CREATE_COMPONENT_PROPERTY(uint64_t, Country);
		/**
		*	俱乐部财政
		*/
		CREATE_COMPONENT_FUNCTION(Finance, Finance);
	protected:
		 
	};
}