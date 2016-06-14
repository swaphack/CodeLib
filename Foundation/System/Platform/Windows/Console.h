#pragma once
#include <string>
#include "../macros.h"

namespace sys
{
	class Console : public ConsoleImpl
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
	private:
		std::string _word;
	};

	#define G_CONSOLE Instance<Console>::getInstance()
}