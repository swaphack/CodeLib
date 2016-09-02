#pragma once

#include "IPerson.h"

namespace game
{
	class IBody;
	class IAction;

	/**
	*	运动员
	*/
	class IPlayer : public IPerson
	{
	public:
		virtual ~IPlayer(){}
	public:
		/**
		*	动作表现信息
		*/
		virtual const IBody* getBody() const = 0;
		/**
		*	执行动作
		*/
		virtual bool runAction(IAction* pAction);
	};
}