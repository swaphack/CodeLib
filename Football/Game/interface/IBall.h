#pragma once

namespace game
{
	/**
	*	��������
	*/
	class IBall
	{
	public:
		virtual ~IBall() {}
	public:
		/**
		*	�뾶
		*/
		virtual float getRadius() const = 0;
		/**
		*	����
		*/
		virtual float getWeight() const = 0;
	};
}