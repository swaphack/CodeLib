#pragma once

#include "../people/Person.h"

namespace game
{
	class Person;

	class Player : public Person
	{
	public:
		Player();
		virtual ~Player();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(Player);
	};
}