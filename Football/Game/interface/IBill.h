#pragma once

namespace game
{
	/**
	*	�˵�
	*/
	class IBill
	{
	public:
		virtual ~IBill() = 0;
	public:
		/**
		*	�����
		*/
		virtual void addItem(int nType, int money) = 0;
		/**
		*	����
		*/
		virtual int getBlance() const = 0;
	};
}