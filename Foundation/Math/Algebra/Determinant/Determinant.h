#pragma once
#include <cstdint>
#include <string>

#include "Basic/Array2D.h"

namespace math
{
	/**
	*	行列式
	*/
	template<const int Order>
	struct Determinant : public Array2D<float, Order, Order>
	{
		typedef Array2D<float, Order, Order> base;
	public:
		Determinant()
		{
		}
		Determinant(const float* val)
		{
			this->assign(val);
		}
		Determinant(const Determinant& det)
		{
			this->assign(det.getValue());
		}
		virtual ~Determinant()
		{
		}
	public:
		/**
		*	阶数
		*/
		int getOrder() const
		{
			return Order;
		}
	public:
		/**
		*	行列式相乘
		*/
		Determinant operator*(const Determinant& det)
		{
			Determinant result;

			float val = 0;
			for (int bh = 0; bh < getOrder(); bh++)
			{
				for (int mw = 0; mw < getOrder(); mw++)
				{
					val = 0;
					for (int mh = 0; mh < getOrder(); mh++)
					{
						float a = base::getValue(bh, mh);
						float b = det.getValue(mh, mw);
						val += a * b;
					}
					result.setValue(bh, mw, val);
				}
			}

			return result;
		}
	public:
		/**
		*	相乘
		*/
		Determinant mul(float k, int row)
		{
			assert(row < getOrder());

			Determinant det;

			for (int i = 0; i < getOrder(); i++)
			{
				det[row * getOrder() + i] = k;
			}

			return det;
		}
		/**
		*	相加
		*/
		Determinant add(const Determinant& det, int row)
		{
			assert(det.getOrder() != this->getOrder());
			int order = getOrder();
			Determinant target(order);

			for (int i = 0; i < order; i++)
			{
				if (i == row)
				{
					for (int j = 0; j < order; j++)
					{
						target.setValue(i, j, base::getValue(i, j) + det.getValue(i, j));
					}
				}
				else if (i != row)
				{
					for (int j = 0; j < order; j++)
					{
						assert(det.getValue(i, j) == base::getValue(i, j));
						target.setValue(i, j, base::getValue(i, j));
					}
				}
			}

			return target;
		}
		
		/**
		*	余子式
		*/
		Determinant<Order - 1> getMinor(int i, int j) const
		{
			assert(i >= 0 && j >= 0 && i < Order && j < Order);

			//int order = getOrder() - 1;
			Determinant<Order - 1> det;
			int dn = 0;
			int dm = 0;

			for (int h = 0; h < Order; h++)
			{
				if (h == i)
				{
					dn++;
					continue;
				}
				dm = 0;
				for (int w = 0; w < Order; w++)
				{
					if (w == j)
					{
						dm++;
						continue;
					}
					det.setValue(h - dn, w - dm, base::getValue(h, w));
				}
			}

			return det;
		}
	public:
		/**
		*	获取逆序数
		*/
		static int getInverseNumber(float* data, int len)
		{
			if (data == nullptr)
			{
				return 0;
			}
			int count = 0;
			for (int i = 0; i < len; i++)
			{
				int num = 0;
				float val = data[i];
				for (int j = i + 1; j < len; j++)
				{
					if (val > data[j])
					{
						num++;
					}
				}
				count += num;
			}

			return count;
		}

		/*
		float getMagnitude()
		{
			assert(getOrder() > 0);
			if (getOrder() == 1)
			{
				return _values[0][0];
			}
			else if (getOrder() == 2)
			{
				return _values[0][0] * _values[1][1] - _values[0][1] * _values[1][0];
			}
			else
			{
				float mag = 0;
				for (int i = 0; i < getOrder(); i++)
				{
					int len = getOrder() - 1;
					int x = 0;
					Determinant<Order - 1> det = getMinor(0, i);
					float k = getValue((int)0, i) * det.getMagnitude() * powf(-1.0f, i);
					mag += k;
				}

				return mag;
			}
		}
		*/
	};


	struct Determinant2 : public Determinant<2> 
	{
		Determinant2() {}
		Determinant2(const float* value)
		{
			this->assign(value);
		}
		Determinant2(float x0, float x1, float x2, float x3)
		{
			(*this)[0] = x0;
			(*this)[1] = x1;
			(*this)[2] = x2;
			(*this)[3] = x3;
		}
	};
	struct Determinant3 : public Determinant<3> 
	{
	};


	static float getDeterminantMagnitude(const Determinant<1>& value)
	{
		return value.getValue(0);
	}

	static float getDeterminantMagnitude(const Determinant<2>& value)
	{
		return value.getValue(0) * value.getValue(3) - value.getValue(1) * value.getValue(2);
	}

	template <const int N>
	static float getDeterminantMagnitude(const Determinant<N>& value)
	{
		float mag = 0;
		for (int i = 0; i < N; i++)
		{
			Determinant<N - 1> det = value.getMinor(0, i);
			float r = i % 2 == 0 ? 1.0f : -1.0f;
			float k = value.getValue(0, i) * getDeterminantMagnitude(det) * r;
			mag += k;
		}

		return mag;
	}

}