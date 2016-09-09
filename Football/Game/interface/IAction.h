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
	class IAction : public ITimer
	{
	public:
		virtual ~IAction() {}
	public:
		/**
		*	发起者
		*/
		virtual const IPerson* getInitiator() const = 0;
		/**
		*	执行动作
		*/
		virtual void run() = 0;
		/**
		*	是否结束
		*/
		virtual bool isFinish() = 0;
	};

	/**
	*	球员比赛动作
	*/
	class IPlayerAction : public ITimer
	{
	public:
		virtual ~IPlayerAction() {}
	public:
		/**
		*	发起者
		*/
		virtual const IPlayer* getPlayer() const = 0;
		/**
		*	执行动作
		*/
		virtual void run() = 0;
		/**
		*	是否结束
		*/
		virtual bool isFinish() = 0;
	};
}