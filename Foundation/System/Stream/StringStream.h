#pragma once

#include "Stream.h"
#include <string>

namespace sys
{
	/*
	�ַ����� ĩβ��\0
	Unixϵͳ�ÿ�н�βֻ�С�<����>��������\\n����
	Windowsϵͳ���棬ÿ�н�β�ǡ�<�س�><����>��������\r\\n����
	Macϵͳ�ÿ�н�β�ǡ�<�س�>��,����\r����
	*/
	class StringStream : public Stream
	{
	public:
		StringStream();
		StringStream(const char* text);
		StringStream(const char* text, int size);
		virtual ~StringStream();
	public:
		// ��ȡһ��
		std::string readLine();
		// д���ַ���
		void writeString(const char* line, int size);
		// д��һ���ַ���
		void writeLine(const char* line, int size);
		// д�����
		void writeLine();
		// �Ƿ��������
		bool readEnd();
	};
}