#pragma once

#include <string>

namespace math
{
	// 符号
	class Symbol
	{
	public:
		Symbol() {}
		virtual ~Symbol() {}
	public:
		// 设置名称
		inline void setName(const char* value) { _name = value; }
		// 获取名称
		inline const char* getName() { return _name.c_str(); }
	private:
		// 符号名称
		std::string _name;
	};
}