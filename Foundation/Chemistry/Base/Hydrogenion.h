#pragma once

#include "Constitution.h"

#include <map>
#include <set>
#include <string>

namespace chem
{
	/**
	*	����
	*	��׼:NH4+,AL3+
	*/
	class Hydrogenion : public Constitution
	{
	public:
		Hydrogenion();
		virtual	~Hydrogenion();
	public:
		// ���ñ��ʽ
		virtual void setExpression(const char* expression);
		// ����Ԫ��
		Elements::const_iterator elementBegin();
		Elements::const_iterator elementEnd();
		// ��ȡ�������
		int getCharge();
	private:
		// �����ṹ,δ���
		void parseConstitution();
	private:
		// ����Ԫ�� {Ԫ�أ�����}
		Elements _elements;
		// �������
		int _charge;
	};
}