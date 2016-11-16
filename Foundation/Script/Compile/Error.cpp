#include "Error.h"

#include <cstdarg>
#include <cstdlib>

using namespace script;


Error::Error(const char* msg)
{
	m_sErrorMsg = msg;
}

Error::~Error()
{

}

const char* Error::getMessage()
{
	return m_sErrorMsg.c_str();
}

extern Error* makeError(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);

	int size = _vscprintf(format, ap) + 1;
	char* value = new char[size];
	memset(value, 0, size);

	vsprintf(value, format, ap);
	va_end(ap);

	delete value;

	return new Error(value);
}
