#pragma once

#include <cstdint>

#include "Complex.h"
#include "Basic/Array2D.h"
#include "Number/Complex.h"

namespace math
{
	/**
	*	����
	*/
	struct Matrixi : public Array2D<Complex>
	{
	public:
		Matrixi(int h, int w);
		virtual ~Matrixi();
	public:
		/**
		*	�������
		*/
		virtual Matrixi operator+(const Matrixi& mat);
		/**
		*	�������
		*/
		virtual Matrixi operator-(const Matrixi& mat);
		/**
		*	�������
		*/
		virtual Matrixi operator*(const Matrixi& mat);
		/**
		*	�������
		*/
		virtual Matrixi& operator+=(const Matrixi& mat);
		/**
		*	�������
		*/
		virtual Matrixi& operator-=(const Matrixi& mat);
		/**
		*	������չϵ��
		*/
		virtual Matrixi& operator*=(float k);
	};
}