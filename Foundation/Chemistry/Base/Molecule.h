#pragma once

#include "Constitution.h"

#include <map>
#include <set>
#include <string>

namespace chem
{
	/**
	*	分子
	*	标准:H2, Al(OH)3
	*/
	class Molecule : public Constitution
	{
	public:
		Molecule();
		virtual ~Molecule();
	public:
		// 设置表达式
		virtual void setExpression(const char* expression);
		// 构成元素
		Elements::const_iterator elementBegin();
		Elements::const_iterator elementEnd();
	private:
		// 解析结构
		void parseConstitution();
	private:
		// 构成元素 {元素，个数}
		Elements _elements;
	};
}