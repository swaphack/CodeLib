#pragma once

namespace game
{
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
	};
}