#pragma once
#include <cstdint>

#include "Function/Function.h"

namespace math
{
	// 多项式
	class Polynomial : public Function
	{
	protected:
		// 单元值
		float* _values = nullptr;
		// 列数
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