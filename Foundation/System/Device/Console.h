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
		// ��ȡһ��
		virtual std::string readLine();
		// ��ȡһ���ַ�
		virtual char readChar();
		// д��һ��
		virtual void writeLine(const std::string& words);
		// д��һ���ַ�
		virtual void writeChar(char word);
	};

#define G_CONSOLE Instance<Console>::getInstance()
}