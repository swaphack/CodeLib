#pragma once

#include <string>
#include <map>

namespace math
{
	// 脚本文本
	class ScriptText
	{
	public:
		ScriptText();
		virtual ~ScriptText();
	public:
		// 导入字符串
		bool loadString(const char* value);
		// 导出字符串
		const char* getString();
	protected:
		// 标准化字符串，去除多余无用的字符
		bool standardize(char* value);
	private:
		// 字符串
		char* _value;
		// 分配内存
		int _capacity;
		// 游标偏移量
		int _offset;
	};
}