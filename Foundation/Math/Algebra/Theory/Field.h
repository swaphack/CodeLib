#pragma once

#include "Ring.h"

namespace math
{
	/**
	*	��(Field)
	*	�ڽ������Ļ����ϣ��������˶�Ԫ���������Ҫ��Ԫ��(��������)�������������㣬��ÿ�������Ԫ�ض�Ҫ�г˷���Ԫ��
	*	�ɴ˿ɼ�������һ�ֿ��Խ��мӼ��˳�(��0����)�Ĵ����ṹ��������������������ƹ㡣
	*	�������ϣ������ڳ˷���Ԫ(1/3��������)�������������ϲ�����
	*	��������ʵ�������������γ��򣬷ֱ����������ʵ���򡢸�����
	*/
	class Field : public CommutativeRing
	{
	public:
		Field doOperatorDiv(const Field& a, const Field& b)
		{
			return Field();
		}
	};
}