#pragma once

#include "../base/Component.h"

namespace game
{
	/**
	*	˼��
	*/
	class Mind : public Component
	{
	public:
		Mind();
		virtual ~Mind();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Mind);

	};
}