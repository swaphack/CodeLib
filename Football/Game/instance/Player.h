#pragma once

#include "../interface/IPlayer.h"
#include "Person.h"

namespace game
{
	class Player : public Person, public IPlayer
	{
	public:
		Player(Person& person);
		virtual ~Player();
	public:

	};
}