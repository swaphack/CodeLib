#pragma once

#include "Types.h"

namespace sys
{
	class BitConvert
	{
	private:
		BitConvert();
		~BitConvert();
	public:
		// ��ȡ10�����������ַ���
		static void getNumberString(int32 number, std::string& value);
		// ��ȡ10�����������ַ���
		static void getNumberString(long number, std::string& value);
		// ��ȡ10�����������ַ���
		static void getNumberString(ulong number, std::string& value);
		// ��ȡ10����˫���ȵ��ַ���
		static void getNumberString(double number, std::string& value);
	protected:
	private:
	};
}