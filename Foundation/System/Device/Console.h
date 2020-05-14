#pragma once

#include "IConsoleImpl.h"
#include <string>

namespace sys
{
	class Console : public IConsoleImpl
	{
	public:
		Console();
		virtual ~Console();
	public:
		// 读取一行
		virtual std::string readLine();
		// 读取一个字符
		virtual char readChar();
		// 写入一行
		virtual void writeLine(const std::string& words);
		// 写入一个字符
		virtual void writeChar(char word);
	};

#define G_CONSOLE Instance<Console>::getInstance()
}