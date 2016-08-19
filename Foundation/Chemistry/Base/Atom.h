#pragma once

#include "Constitution.h"

#include <map>
#include <set>
#include <string>

namespace chem
{
	/**
	*	ԭ��
	*	��׼:Ag
	*/
	class Atom : public Constitution
	{
	public:
		Atom();
		virtual ~Atom();
	public:
		// ���ñ��ʽ
		virtual void setExpression(const char* expression);
		// ��ȡԪ�ر�ʶ
		int getElement();
	private:
		// �����ṹ
		void parseConstitution();
	private:
		// Ԫ��
		int _element;
	};
}