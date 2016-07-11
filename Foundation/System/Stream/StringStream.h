#pragma once

#include "Stream.h"
#include <string>

namespace sys
{
	/*
	Unixϵͳ�ÿ�н�βֻ�С�<����>��������\n����
	Windowsϵͳ���棬ÿ�н�β�ǡ�<�س�><����>��������\r\n����
	Macϵͳ�ÿ�н�β�ǡ�<�س�>��,����\r����
	*/
	// �ַ�����
	class StringStream : public Stream
	{
	public:
		StringStream();
		StringStream(const char* text);
		virtual ~StringStream();
	public:
		// ��ȡһ��
		std::string readLine();
		void writeString(const char* line, int size);
		// д��һ��
		void writeLine(const char* line, int size);
		// д�����
		void writeLine();
		// �Ƿ��������
		bool readEnd();
	protected:
	private:
	};
}