#pragma once

namespace game
{
	class IBody;
	class IAction;

	/**
	*	比赛用球
	*/
	class IBall
	{
	public:
		virtual ~IBall() {}
	public:
		/**
		*	半径
		*/
		virtual float getRadius() const = 0;
		/**
		*	重量
		*/
		virtual float getWeight() const = 0;
		/**
		*	身体，用于动作表现
		*/
		virtual IBody* getBody() = 0;
		/**
		*	执行动作
		*/
		virtual bool runAction(IAction* pAction) = 0;
	};
}