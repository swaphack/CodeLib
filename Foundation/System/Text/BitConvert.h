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
		// 获取10进制整数的字符串
		static void getNumberString(int32_t number, std::string& value);
		// 获取10进制整数的字符串
		static void getNumberString(long number, std::string& value);
		// 获取10进制整数的字符串
		static void getNumberString(uint64_t number, std::string& value);
		// 获取10进制双精度的字符串
		static void getNumberString(double number, std::string& value);
	protected:
	private:
	};
}