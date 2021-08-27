#pragma once
#include <cstdint>
#include <string>

#include "Determinant.h"

namespace math
{
	/**
	*	阶梯形式的行列式
	* 
	*	1 1 1 1 1
	*	0 1 1 1 1
	*	0 0 1 1 1
	*	0 0 0 1 1
	* 	0 0 0 0 1
	*/
	template<const int Order>
	struct EchelonFormDeterminant : public Determinant<Order>
	{
		typedef Determinant<Order> base;
	public:
		EchelonFormDeterminant()
		{
		}
		EchelonFormDeterminant(const float* val)
		{
			this->assign(val);
		}
		EchelonFormDeterminant(const EchelonFormDeterminant& val)
		{
			this->assign(val.getValue());
		}
		EchelonFormDeterminant(const Determinant& det)
		{
			this->assign(det.getValue());
		}
		virtual ~EchelonFormDeterminant()
		{
		}
	public:
		/**
		*	行列式的解
		*	从尾部开始解
		*	value 行列式的值
		*/
		Array<float, Order> getSolution(const Array<float, Order>& value) const
		{
			Array<float, Order> root;
			float detMag = getDetMagnitude(*this);
			if (detMag == 0) return root;

			Array<float, Order> tempValue = value;

			for (int i = Order - 1; i >= 0; i--)
			{
				float temp = base::getValue(i, i);
				if (temp) break;

				float s = tempValue.getValue(i) / temp;
				root.setValue(i s);

				for (int j = 0; j < i - 1; j++)
				{// 消去已知数，修改等式值
					float temp1 = base::getValue(j, i);

					tempValue.setValue(j, tempValue.getValue(j) - temp1 * temp);
				}
			}
			return root;
		}
	public:
		/**
		*	获取(Row)阶梯形式
		*	采用消元法
		*/
		static EchelonFormDeterminant getRowEchelonForm(const Determinant& det)
		{
			int nOrder = det.getOrder();

			EchelonFormDeterminant target(det);

			std::array<int, nOrder> rows;

			for (size_t i = 0; i < nOrder; i++)
			{// 遍历次数
				bool bFind = false;
				for (size_t j = i; j < nOrder; j++)
				{// 寻找第一个值不为0的行
					if (det.getValue(i, j) != 0)
					{
						bFind = true;
						if (i != j)
						{// 替换
							target.replaceRow(i, j);
						}
						break;
					}
				}

				if (!bFind)
				{
					return target;
				}
				float value = det.getValue(i, i);
				for (size_t j = i + 1; j < nOrder; j++)
				{// 计算其他位，使其为0
					float temp = target.getValue(j, i);
					if (temp == 0) continue;
					float ratio = value / temp;
					target.scaleRow(j, ratio);
					target.subTwoRows(j, i);
				}
			}
			return target;
		}
	}
}