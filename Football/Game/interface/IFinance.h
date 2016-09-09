#pragma once

namespace game
{
	class IBill;
	/**
	*	财政
	*/
	class IFinance
	{
	public:
		virtual ~IFinance() {}
	public:
		/**
		*	添加钱财
		*/
		virtual void addMoney(unsigned int money) = 0;
		/**
		*	减少钱财
		*/
		virtual void subMoney(unsigned int money) = 0;
		/**
		*	结余
		*/
		virtual int getBlance() const = 0;
		/**
		*	是否赤字
		*/
		virtual bool isDeficit() const = 0;
		/**
		*	获取在周期中的财政支出
		*/
		virtual int getExpenditure() const = 0;
		/**
		*	获取在周期中的财政收入
		*/
		virtual int getIncome() const = 0;
		/**
		*	处理账单
		*/
		virtual void handle(IBill* pBill) = 0;
	};
}