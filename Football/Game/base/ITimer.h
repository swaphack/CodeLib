#pragma once

namespace game
{
	/**
	*	定时器
	*/
	class ITimer
	{
	public:
		virtual ~ITimer() {}
	public:
		/**
		*	更新
		*/
		virtual void update(float dt) = 0;
	};
}