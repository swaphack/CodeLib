#pragma once

#include "IAction.h"

namespace game
{
	class IPlayer;
	struct Parabola;
	/**
	*	停球（非守门员除手外）动作
	*/
	class ICatchAction : public IActionWithBall
	{
	public:
		virtual ~ICatchAction() {}
	public:
	};
}