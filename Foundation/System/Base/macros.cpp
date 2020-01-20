#include "macros.h"

#include <cstring>
#include <cstdarg>
#include <cstdio>

const char* getCString(const char* format, ...)
{
	static char g_StringValue[255] = { 0 };
	memset(g_StringValue, 0, 255);

	va_list ap;
	va_start(ap, format);
	vsprintf(g_StringValue, format, ap);
	va_end(ap);

	return g_StringValue;
}