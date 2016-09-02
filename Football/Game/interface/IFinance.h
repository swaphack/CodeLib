#pragma once

namespace game
{
	class IContract;
	/**
	*	财政
	*/
	class IFinance
	{
	public:
		virtual ~IFinance() {}
	public:
		/**
		*	添加一份协议
		*/
		virtual void addContract(IContract* pContract) = 0;
		/**
		*	移除一份协议
		*/
		virtual void removeContract(IContract* pContract) = 0;
		/**
		*	结余
		*/
		virtual int getBlance() const = 0;
	};
}