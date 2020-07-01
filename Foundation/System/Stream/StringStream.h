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
		StringStream(const std::string& text);
		StringStream(const char* text, size_t size);
		virtual ~StringStream();
	public:
		// �ַ�����ʼ��
		void initWithData(const std::string& text);
		// �ַ�����ʼ��
		void initWithData(const char* content, size_t size);
		// ��ȡһ��
		void readLine(std::string& text);
		// ��ȡʣ��
		void readRemain(std::string& text);
		// д���ַ���
		void writeString(const char* line, size_t size);
		// д���ַ���
		void writeString(const std::string& text);
		// д��һ���ַ���
		void writeLine(const char* line, size_t size);
		// д��һ���ַ���
		void writeLine(const std::string& text);
		// д�����
		void writeLine();
		// �Ƿ��������
		bool readEnd();
	};
}