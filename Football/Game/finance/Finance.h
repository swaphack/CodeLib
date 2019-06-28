#pragma once

#include "../base/Component.h"

namespace game
{
	/**
	*	²ÆÕþ
	*/
	class Finance : public Component
	{
	public:
		Finance();
		virtual ~Finance();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Finance);
	public:
	};
}