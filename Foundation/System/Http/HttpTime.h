#pragma once

#include <string>
#include <cstdint>

namespace sys
{
	class DateTime;

	/*
	Sun, 06 Nov 1994 08:49:37 GMT  ; RFC 822, updated by RFC 1123
	Sunday, 06-Nov-94 08:49:37 GMT ; RFC 850, obsoleted by RFC 1036
	Sun Nov  6 08:49:37 1994       ; ANSI C's asctime() format
	*/
	class HttpTime
	{
	public:
		// 时间长度
		static const int32_t TIME_COUNT = 255;
		// 星期
		static const char* TIME_WKDAY[7];
		// 星期	   c  har*
		static const char* TIME_WEEKDAY[7];
		// 月份	   c  har*
		static const char*	TIME_MONTH[12];
	public:
		// 获取 RFC 822 时间格式
		static std::string getRFC822Time(DateTime* time);

		// 获取 RFC 822 时间格式
		static std::string getRFC850Time(DateTime* time);

		// 获取 RFC 822 时间格式
		static std::string getANSITime(DateTime* time);
	};
}