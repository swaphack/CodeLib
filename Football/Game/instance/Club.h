#pragma once

#include "Component.h"
#include "../interface/IClub.h"

namespace game
{
	/**
	*	���ֲ�
	*/
	class Club : public Component, public IClub
	{
	public:
		Club();
		virtual ~Club();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Club);
	public:
		 
	};
}