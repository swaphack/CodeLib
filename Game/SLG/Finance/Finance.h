#pragma once

namespace slg
{
	// ����
	class Finance
	{
	public:
		virtual ~Finance() {}
	public:
		// ����
		virtual void income(unsigned int money) = 0;
		// ֧��
		virtual void expenditure(unsigned int money) = 0;
		// ���
		virtual unsigned int getBalance() = 0;
	protected:
	private:
	};
}