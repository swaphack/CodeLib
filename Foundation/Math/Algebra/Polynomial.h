#pragma once
#include <cstdint>

#include "Function/Function.h"

namespace math
{
	// ����ʽ
	class Polynomial : public Function
	{
	protected:
		// ��Ԫֵ
		float* _values = nullptr;
		// ����
		int32_t _count = 0;
	public:
		Polynomial();
		Polynomial(float* val, int32_t len);
		Polynomial(const Polynomial& vec);
		virtual ~Polynomial();
	public:
		//virtual Decimal getValue(float t);

	private:
	};
}