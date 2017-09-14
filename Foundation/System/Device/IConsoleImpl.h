#pragma once

namespace sys
{
	class IConsoleImpl
	{
	public:
		virtual ~IConsoleImpl() {}
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