#include "StringStream.h"

using namespace sys;


StringStream::StringStream() 
:Stream(new StreamBaseRef())
{

}

StringStream::StringStream(const char* text)
: Stream(new StreamBaseRef())
{
	this->setData(text, strlen(text));
}

StringStream::~StringStream()
{
	SAFE_DELETE(_baseStream);
}

std::string StringStream::readLine()
{
	char* cursor = getPtr();
	char* ptr = getPtr();

	while (ptr != nullptr
#if PLATFORM_TARGET == EPT_WINDOWS
		&& !(*(ptr - 1) == '\r' && *(ptr) == '\n')
#elif PLATFORM_TARGET == EPT_MAC
		&& !(*(ptr) == '\r')
#elif PLATFORM_TARGET == EPT_LINUX
		&& !(*(ptr) == '\n')
#endif
		&& (*ptr) != 0)
	{
		ptr++;
	}
	ptr++;
	ss_t size = ptr - cursor;
	this->setCursor(getCursor() + size);
	return std::string(cursor, size);
}

void StringStream::writeLine(const char* line)
{
	std::size_t size = strlen(line);
	int ext = 0;
#if PLATFORM_TARGET == EPT_WINDOWS
	ext = 2;
#elif PLATFORM_TARGET == EPT_MAC
	ext = 1;
#elif PLATFORM_TARGET == EPT_LINUX
	ext = 1;
#endif
	if (size + ext + getCursor() > this->getCapacity())
	{
		char* newData = StreamHelper::mallocStream(size + ext + this->getCursor(), (char*)this->getData(), this->getCapacity());
	}
	
	char* ptr = getPtr();
	memcpy(ptr, line, size);
#if PLATFORM_TARGET == EPT_WINDOWS
	*(ptr + size) = '\r';
	*(ptr + size + 1) = '\n';
#elif PLATFORM_TARGET == EPT_MAC
	*(ptr + size) = '\r';
#elif PLATFORM_TARGET == EPT_LINUX
	*(ptr + size) = '\n';
#endif
	this->setCursor(getCursor() + size + ext);
}

bool StringStream::readEnd()
{
	return getCursor() >= getCapacity();
}
