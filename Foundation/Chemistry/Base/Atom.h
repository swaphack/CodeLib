#pragma once

#include "Constitution.h"

#include <map>
#include <set>
#include <string>

namespace chem
{
	/**
	*	原子
	*	标准:Ag
	*/
	class Atom : public Constitution
	{
	public:
		Atom();
		virtual ~Atom();
	public:
		// 设置表达式
		virtual void setExpression(const char* expression);
		// 获取元素标识
		int getElement();
	private:
		// 解析结构
		void parseConstitution();
	private:
		// 元素
		int _element;
	};
}