#pragma once

#include "Constitution.h"

#include <map>
#include <set>
#include <string>

namespace chem
{
	/**
	*	����
	*	��׼:H2, Al(OH)3
	*/
	class Molecule : public Constitution
	{
	public:
		Molecule();
		virtual ~Molecule();
	public:
		// ���ñ��ʽ
		virtual void setExpression(const char* expression);
		// ����Ԫ��
		Elements::const_iterator elementBegin();
		Elements::const_iterator elementEnd();
	private:
		// �����ṹ
		void parseConstitution();
	private:
		// ����Ԫ�� {Ԫ�أ�����}
		Elements _elements;
	};
}