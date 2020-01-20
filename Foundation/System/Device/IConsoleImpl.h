#pragma once

#include <string>

namespace sys
{
	class IConsoleImpl
	{
	public:
		virtual ~IConsoleImpl() {}
	public:
		// ��ȡһ��
		virtual const std::string& readLine() = 0;
		// ��ȡһ���ַ�
		virtual char readChar() = 0;
		// д��һ��
		virtual void writeLine(const std::string& words) = 0;
		// д��һ���ַ�
		virtual void writeChar(char word) = 0;
	};
}