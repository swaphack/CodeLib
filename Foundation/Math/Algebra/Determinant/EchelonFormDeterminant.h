#pragma once
#include <cstdint>
#include <string>

#include "Determinant.h"

namespace math
{
	/**
	*	������ʽ������ʽ
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
		*	����ʽ�Ľ�
		*	��β����ʼ��
		*	value ����ʽ��ֵ
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
				{// ��ȥ��֪�����޸ĵ�ʽֵ
					float temp1 = base::getValue(j, i);

					tempValue.setValue(j, tempValue.getValue(j) - temp1 * temp);
				}
			}
			return root;
		}
	public:
		/**
		*	��ȡ(Row)������ʽ
		*	������Ԫ��
		*/
		static EchelonFormDeterminant getRowEchelonForm(const Determinant& det)
		{
			int nOrder = det.getOrder();

			EchelonFormDeterminant target(det);

			std::array<int, nOrder> rows;

			for (size_t i = 0; i < nOrder; i++)
			{// ��������
				bool bFind = false;
				for (size_t j = i; j < nOrder; j++)
				{// Ѱ�ҵ�һ��ֵ��Ϊ0����
					if (det.getValue(i, j) != 0)
					{
						bFind = true;
						if (i != j)
						{// �滻
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
				{// ��������λ��ʹ��Ϊ0
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