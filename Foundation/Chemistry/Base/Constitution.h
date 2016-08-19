#pragma once

#include "macros.h"

#include <map>
#include <set>
#include <string>

namespace chem
{
	// Ԫ����Ϣ {Ԫ��id,Ԫ�ظ���}
	typedef std::map<int, int> Elements;

	/**
	*	��ѧ�ṹ(һ�����ʵķ��ű�ʶ)
	*/
	class Constitution
	{
	public:
		Constitution();
		virtual ~Constitution();
	public:
		// ���ñ��ʽ
		virtual void setExpression(const char* expression);
		// ��ȡ���ʽ
		const char* getExpression();
	protected:// ���ʽ
		std::string _expression;
	};
}