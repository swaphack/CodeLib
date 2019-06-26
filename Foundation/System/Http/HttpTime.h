#pragma once

#include "Base/import.h"

namespace sys
{
	/*
	Sun, 06 Nov 1994 08:49:37 GMT  ; RFC 822, updated by RFC 1123
	Sunday, 06-Nov-94 08:49:37 GMT ; RFC 850, obsoleted by RFC 1036
	Sun Nov  6 08:49:37 1994       ; ANSI C's asctime() format
	*/
	class HttpTime
	{
	public:
		// ʱ�䳤��
		static const int32 TIME_COUNT = 255;
		// ����
		static const char* TIME_WKDAY[7];
		// ����
		static const char* TIME_WEEKDAY[7];
		// �·�
		static const char*	TIME_MONTH[12];
	public:
		// ��ȡ RFC 822 ʱ���ʽ
		static const char* getRFC822Time(Time* time);

		// ��ȡ RFC 822 ʱ���ʽ
		static const char* getRFC850Time(Time* time);

		// ��ȡ RFC 822 ʱ���ʽ
		static const char* getANSITime(Time* time);
	};
}