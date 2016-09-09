#pragma once

#include "ITimer.h"

namespace game
{
	class IPerson;
	class IPlayer;
	class IBall;

	/**
	*	��������
	*/
	class IAction : public ITimer
	{
	public:
		virtual ~IAction() {}
	public:
		/**
		*	������
		*/
		virtual const IPerson* getInitiator() const = 0;
		/**
		*	ִ�ж���
		*/
		virtual void run() = 0;
		/**
		*	�Ƿ����
		*/
		virtual bool isFinish() = 0;
	};

	/**
	*	��Ա��������
	*/
	class IPlayerAction : public ITimer
	{
	public:
		virtual ~IPlayerAction() {}
	public:
		/**
		*	������
		*/
		virtual const IPlayer* getPlayer() const = 0;
		/**
		*	ִ�ж���
		*/
		virtual void run() = 0;
		/**
		*	�Ƿ����
		*/
		virtual bool isFinish() = 0;
	};
}