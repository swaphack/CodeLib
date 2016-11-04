#pragma once

#include "../interface/IPlayer.h"
#include "Component.h"

namespace game
{
	class Person;

	class Player : public Component, public IPlayer
	{
	public:
		Player();
		virtual ~Player();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Player);
	};
}