#pragma once

#include "../base/Component.h"

namespace game
{
	/**
	*	Ë¼¿¼
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