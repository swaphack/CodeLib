#pragma once

#include "ITimer.h"

namespace game
{
	class IPerson;
	class IPlayer;
	class IBall;

	/**
	*	比赛动作
	*/
	class IAction
	{
	public:
		virtual ~IAction() {}
	public:
		/**
		*	发起者
		*/
		virtual IPerson* getInitiator() = 0;
		/**
		*	执行动作
		*/
		virtual bool run() = 0;
		/**
		*	是否结束
		*/
		virtual bool isFinish() = 0;
	};
}