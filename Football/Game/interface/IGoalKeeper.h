#pragma once

#include "IPlayer.h"

namespace game
{
	class IBall;

	/**
	*	����Ա
	*/
	class IGoalKeeper : public IPlayer
	{
	public:
		virtual ~IGoalKeeper(){}
	};
}