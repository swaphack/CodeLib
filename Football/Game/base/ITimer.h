#pragma once

namespace game
{
	/**
	*	��ʱ��
	*/
	class ITimer
	{
	public:
		virtual ~ITimer() {}
	public:
		/**
		*	����
		*/
		virtual void update(float dt) = 0;
	};
}