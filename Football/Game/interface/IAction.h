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
	class IAction
	{
	public:
		virtual ~IAction() {}
	public:
		/**
		*	������
		*/
		virtual IPerson* getInitiator() = 0;
		/**
		*	ִ�ж���
		*/
		virtual bool run() = 0;
		/**
		*	�Ƿ����
		*/
		virtual bool isFinish() = 0;
	};
}