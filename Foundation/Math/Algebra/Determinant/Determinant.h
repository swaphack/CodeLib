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
		void scaleRow(int row, float k)
		{
			assert(row >= 0 && row < getOrder());

			for (int i = 0; i < getOrder(); i++)
			{
				int index = row * getOrder() + i;
				base::setValue(index, base::getValue(index) * k);
			}
		}
		/**
		*	相加
		*	将两行相加的值放在第一行
		*/
		void addTwoRows(int row0, int row1)
		{
			assert(row0 >= 0 && row0 < getOrder());
			assert(row1 >= 0 && row1 < getOrder());

			for (int i = 0; i < getOrder(); i++)
			{
				int index0 = row0 * getOrder() + i;
				int index1 = row1 * getOrder() + i;

				base::setValue(index0, base::getValue(index0) + base::getValue(index1));
			}
		}
		/**
		*	相减
		*	将两行相减的值放在第一行
		*/
		void subTwoRows(int row0, int row1)
		{
			assert(row0 >= 0 && row0 < getOrder());
			assert(row1 >= 0 && row1 < getOrder());

			for (int i = 0; i < getOrder(); i++)
			{
				int index0 = row0 * getOrder() + i;
				int index1 = row1 * getOrder() + i;

				base::setValue(index0, base::getValue(index0) - base::getValue(index1));
			}
		}
	public:
		/**
		*	相加
		*/
		Determinant addWithRow(const Determinant& det, int row)
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
		/**
		*	行列式的解 
		*	value 行列式的值
		*/
		Array<float, Order> getSolution(const Array<float, Order>& value) const
		{
			Array<float, Order> root;
			float detMag = getDetMagnitude(*this);
			if (detMag == 0) return root;

			for (int i = 0; i < Order; i++)
			{
				Determinant<Order> det(*this);
				det.setColumn(i, value);
				root.setValue(i, getDetMagnitude(det) / detMag);
			}
			return root;
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
	};

	typedef Determinant<1> Determinant1;
	typedef Determinant<2> Determinant2;
	typedef Determinant<3> Determinant3;
	typedef Determinant<4> Determinant4;

	static float getDetMagnitude(const Determinant1& value)
	{
		return value.getValue(0);
	}

	static float getDetMagnitude(const Determinant2& value)
	{
		return value.getValue(0) * value.getValue(3) 
			- value.getValue(1) * value.getValue(2);
	}

	static float getDetMagnitude(const Determinant3& value)
	{
		return value.getValue(0) * (value.getValue(4) * value.getValue(8) - value.getValue(5) * value.getValue(7))
			- value.getValue(1) * (value.getValue(3) * value.getValue(8) - value.getValue(5) * value.getValue(6))
			+ value.getValue(2) * (value.getValue(3) * value.getValue(7) - value.getValue(4) * value.getValue(6));
	}

	template <const int N>
	static float getDetMagnitude(const Determinant<N>& value)
	{
		float mag = 0;
		for (int i = 0; i < N; i++)
		{
			Determinant<N - 1> det = value.getMinor(0, i);
			float r = i % 2 == 0 ? 1.0f : -1.0f;
			float k = value.getValue(0, i) * getDetMagnitude(det) * r;
			mag += k;
		}

		return mag;
	}
}