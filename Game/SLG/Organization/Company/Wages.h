#pragma once

namespace slg
{
	// ֧��ʱ������
	enum PaymentTimeType
	{
		// Сʱ
		EPTT_HOUR,
		// ��
		EPTT_DAY,
		// ��
		EPTT_WEEK,
		// ��
		EPTT_MONTH,
		// ��
		EPTT_YEAR,
	};

	// ����
	class Wages
	{
	public:
		Wages();
		~Wages();
	public:
		// ����
		int getPayment();
		void setPayment(int payment);

		// ʱ������
		PaymentTimeType getPayTimeType();
		void setPayTimeType(PaymentTimeType ptt);
	protected:
	private:
		// ����
		int _payment;
		// ֧��ʱ������
		PaymentTimeType _paymentTimeType;
	};
}