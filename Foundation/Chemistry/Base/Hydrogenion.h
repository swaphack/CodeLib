#pragma once

#include "Constitution.h"

#include <map>
#include <set>
#include <string>

namespace chem
{
	/**
	*	离子
	*	标准:NH4+,AL3+
	*/
	class Hydrogenion : public Constitution
	{
	public:
		Hydrogenion();
		virtual	~Hydrogenion();
	public:
		// 设置表达式
		virtual void setExpression(const char* expression);
		// 构成元素
		Elements::const_iterator elementBegin();
		Elements::const_iterator elementEnd();
		// 获取带电荷数
		int getCharge();
	private:
		// 解析结构,未完成
		void parseConstitution();
	private:
		// 构成元素 {元素，个数}
		Elements _elements;
		// 带电荷数
		int _charge;
	};
}