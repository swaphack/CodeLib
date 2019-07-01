#pragma once

#include "../base/Component.h"

namespace game
{
	/**
	*	����
	*/
	class Country : public Component
	{
	public:
		Country();
		virtual ~Country();
	public:
		/**
		*	����
		*/
		CREATE_COMPONENT_PROPERTY(std::string, Name);
	};
}