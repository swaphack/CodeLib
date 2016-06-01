#pragma once

namespace slg
{
	// ����
	class IFinance
	{
	public:
		virtual ~IFinance() {}
	public:
		// ����
		virtual void income(unsigned int money) = 0;
		// ֧��
		virtual void expenditure(unsigned int money) = 0;
		// ���
		virtual unsigned int getBalance() = 0;
	};
}