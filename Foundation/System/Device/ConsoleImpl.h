#pragma once

namespace sys
{
	class ConsoleImpl
	{
	public:
		virtual ~ConsoleImpl() {}
	public:
		// ��ȡһ��
		virtual const char* readLine() = 0;
		// ��ȡһ���ַ�
		virtual char readChar() = 0;
		// д��һ��
		virtual void writeLine(const char* words) = 0;
		// д��һ���ַ�
		virtual void writeChar(char word) = 0;
	};
}