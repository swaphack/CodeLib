#pragma once

#include "IPerson.h"

namespace game
{
	class IBody;
	class IAction;

	/**
	*	�˶�Ա
	*/
	class IPlayer : public IPerson
	{
	public:
		virtual ~IPlayer(){}
	public:
		/**
		*	����������Ϣ
		*/
		virtual const IBody* getBody() const = 0;
		/**
		*	ִ�ж���
		*/
		virtual bool runAction(IAction* pAction);
	};
}