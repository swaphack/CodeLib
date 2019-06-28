#pragma once

namespace game
{
	/**
	*	账单
	*/
	class Bill
	{
	public:
		virtual ~Bill();
	public:
		/**
		*	添加项
		*/
		virtual void addItem(int nType, int money);
		/**
		*	结余
		*/
		virtual int getBlance() const;
	};
}