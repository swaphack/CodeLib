#pragma once

#include "macros.h"

namespace script
{
	// 文本
	class Text : public Variable
	{
	public:
		Text();
		virtual ~Text();
	public:
		// 设置变量值
		void setValue(const char* value);
		// 获取变量值
		const char* getValue();
	public: // 覆盖
		// 克隆
		Text* clone();
		// 分配新的内存，为变量赋值
		Text* alloct(const char* name);
	private:
		std::string m_strValue;
	};
}