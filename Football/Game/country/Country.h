#pragma once

#include "../base/Component.h"

namespace game
{
	/**
	*	¹ú¼Ò
	*/
	class Country : public Component
	{
	public:
		Country();
		virtual ~Country();
	public:
		/**
		*	Ãû³Æ
		*/
		CREATE_COMPONENT_PROPERTY(std::string, Name);
	};
}