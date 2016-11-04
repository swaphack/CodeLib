#pragma once

#include "Component.h"
#include "../interface/IClub.h"

namespace game
{
	/**
	*	æ„¿÷≤ø
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