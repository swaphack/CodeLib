#pragma once

#include "../interface/IMind.h"

#include "Component.h"

namespace game
{
	/**
	*	˼��
	*/
	class Mind : public Component, public IMind
	{
	public:
		Mind();
		virtual ~Mind();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Mind);

	};
}