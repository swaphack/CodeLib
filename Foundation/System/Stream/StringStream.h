#pragma once

#include "Stream.h"
#include "Base/Types.h"

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
		StringStream(const char* text, int32 size);
		virtual ~StringStream();
	public:
		// �ַ�����ʼ��
		void initWithText(const char* text);
		// �ַ�����ʼ��
		void initWithText(const char* text, int32 size);
		// ��ȡһ��
		void readLine(std::string& text);
		// ��ȡʣ��
		void readRemain(std::string& text);
		// д���ַ���
		void writeString(const char* line, int32 size);
		// д���ַ���
		void writeString(const std::string& text);
		// д��һ���ַ���
		void writeLine(const char* line, int32 size);
		// д��һ���ַ���
		void writeLine(const std::string& text);
		// д�����
		void writeLine();
		// �Ƿ��������
		bool readEnd();
	};
}