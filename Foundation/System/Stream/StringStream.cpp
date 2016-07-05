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
	

	int ext = 0;
#if PLATFORM_TARGET == EPT_WINDOWS
	ext = 2;
#elif PLATFORM_TARGET == EPT_MAC
	ext = 1;
#elif PLATFORM_TARGET == EPT_LINUX
	ext = 1;
#endif

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

	return std::string(cursor, size - ext);
}

void StringStream::writeLine(const char* line)
{
	if (line == nullptr)
	{
		return;
	}
	
	int ext = 0;
#if PLATFORM_TARGET == EPT_WINDOWS
	ext = 2;
#elif PLATFORM_TARGET == EPT_MAC
	ext = 1;
#elif PLATFORM_TARGET == EPT_LINUX
	ext = 1;
#endif

	std::size_t size = strlen(line);
	int newCursor = size + ext + this->getCursor();
	if (newCursor + 1 > this->getCapacity())
	{
		char* newData = StreamHelper::mallocStream(newCursor + 1, (char*)this->getData(), this->getCapacity());
		this->setData(newData, newCursor + 1);
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


	this->setCursor(newCursor);
}

void StringStream::writeLine()
{
	this->writeLine("");
}

bool StringStream::readEnd()
{
	return getCursor() >= getCapacity();
}
