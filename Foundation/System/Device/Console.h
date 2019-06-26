#pragma once
#include "Base/Types.h"
#include "IConsoleImpl.h"

namespace sys
{
	class Console : public IConsoleImpl
	{
	public:
		Console();
		virtual ~Console();
	public:
		// 读取一行
		virtual const char* readLine();
		// 读取一个字符
		virtual char readChar();
		// 写入一行
		virtual void writeLine(const char* words);
		// 写入一个字符
		virtual void writeChar(char word);
	};

#define G_CONSOLE sys::Instance<sys::Console>::getInstance()
}