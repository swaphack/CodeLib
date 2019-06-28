#pragma once

#include "IAction.h"

#include <vector>

namespace game
{
	class IPlayer;
	/**
	*	����ʽ�Ķ�������ͷ�����Ƶȵȣ�
	*/
	class IActionCommand : public IAction
	{
	public:
		virtual ~IActionCommand() {}
	public:
		/**
		*	Ҫ��ĳ����ĳ��
		*/
		virtual void wantSomeBodyToDo(IPlayer* pPlayer, IAction* pAction) = 0;
		/**
		*	Ҫ��ĳЩ����ĳ��
		*/
		virtual void wantSomeBodyToDo(std::vector<IPlayer*> pPlayers, IAction* pAction) = 0;
	};
}