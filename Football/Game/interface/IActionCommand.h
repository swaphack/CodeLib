#pragma once

#include "IAction.h"

#include <vector>

namespace game
{
	class IPlayer;
	/**
	*	命令式的动作（口头，手势等等）
	*/
	class IActionCommand : public IAction
	{
	public:
		virtual ~IActionCommand() {}
	public:
		/**
		*	要求某人做某事
		*/
		virtual void wantSomeBodyToDo(IPlayer* pPlayer, IAction* pAction) = 0;
		/**
		*	要求某些人做某事
		*/
		virtual void wantSomeBodyToDo(std::vector<IPlayer*> pPlayers, IAction* pAction) = 0;
	};
}