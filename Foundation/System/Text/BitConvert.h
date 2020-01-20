#pragma once

#include <string>
#include <cstdint>

namespace sys
{
	class BitConvert
	{
	private:
		BitConvert();
		~BitConvert();
	public:
		// ��ȡ10�����������ַ���
		static void getNumberString(int32_t number, std::string& value);
		// ��ȡ10�����������ַ���
		static void getNumberString(long number, std::string& value);
		// ��ȡ10�����������ַ���
		static void getNumberString(uint64_t number, std::string& value);
		// ��ȡ10����˫���ȵ��ַ���
		static void getNumberString(double number, std::string& value);
	protected:
	private:
	};
}