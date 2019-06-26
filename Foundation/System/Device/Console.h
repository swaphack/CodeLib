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
		// ��ȡһ��
		virtual const char* readLine();
		// ��ȡһ���ַ�
		virtual char readChar();
		// д��һ��
		virtual void writeLine(const char* words);
		// д��һ���ַ�
		virtual void writeChar(char word);
	};

#define G_CONSOLE sys::Instance<sys::Console>::getInstance()
}