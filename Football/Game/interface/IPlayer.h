#pragma once

#include "IRole.h"

namespace game
{
	class IBody;
	class IAction;
	class IPlayerMark;

	/**
	*	运动员
	*/
	class IPlayer : public IRole
	{
	public:
		virtual ~IPlayer(){}
	public:
		/**
		*	身体，用于动作表现
		*/
		virtual const IBody* getBody() const = 0;
		/**
		*	球员评估
		*/
		virtual const IPlayerMark* getMark() const = 0;
		/**
		*	执行动作
		*/
		virtual bool runAction(IAction* pAction);
	};
}