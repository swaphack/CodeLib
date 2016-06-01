#pragma once

namespace slg
{
	// 支付时间类型
	enum PaymentTimeType
	{
		// 小时
		EPTT_HOUR,
		// 天
		EPTT_DAY,
		// 周
		EPTT_WEEK,
		// 月
		EPTT_MONTH,
		// 年
		EPTT_YEAR,
	};

	// 工资
	class Wages
	{
	public:
		Wages();
		~Wages();
	public:
		// 报酬
		int getPayment();
		void setPayment(int payment);

		// 时长类型
		PaymentTimeType getPayTimeType();
		void setPayTimeType(PaymentTimeType ptt);
	protected:
	private:
		// 报酬
		int _payment;
		// 支付时长类型
		PaymentTimeType _paymentTimeType;
	};
}