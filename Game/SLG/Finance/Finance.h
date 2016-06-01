#pragma once

namespace slg
{
	// 财政
	class IFinance
	{
	public:
		virtual ~IFinance() {}
	public:
		// 收入
		virtual void income(unsigned int money) = 0;
		// 支出
		virtual void expenditure(unsigned int money) = 0;
		// 余额
		virtual unsigned int getBalance() = 0;
	};
}