#pragma once

#include <string>

namespace sys
{
	class IConsoleImpl
	{
	public:
		virtual ~IConsoleImpl() {}
	public:
		// 读取一行
		virtual const std::string& readLine() = 0;
		// 读取一个字符
		virtual char readChar() = 0;
		// 写入一行
		virtual void writeLine(const std::string& words) = 0;
		// 写入一个字符
		virtual void writeChar(char word) = 0;
	};
}