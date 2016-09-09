#pragma once

namespace game
{
	/**
	*	账单
	*/
	class IBill
	{
	public:
		virtual ~IBill() = 0;
	public:
		/**
		*	添加项
		*/
		virtual void addItem(int nType, int money) = 0;
		/**
		*	结余
		*/
		virtual int getBlance() const = 0;
	};
}