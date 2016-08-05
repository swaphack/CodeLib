#include "StringStream.h"

using namespace sys;


StringStream::StringStream() 
:Stream(new StreamBaseRef())
{

}

StringStream::StringStream(const char* text)
: Stream(new StreamBaseRef())
{
	int len = strlen(text) + 1;

	char* newData = StreamHelper::mallocStream((void*)text, len);

	this->setData(newData, len);
}

StringStream::StringStream(const char* text, int size)
: Stream(new StreamBaseRef())
{
	int len = size + 1;

	char* newData = StreamHelper::mallocStream((void*)text, len);
	newData[size] = '\0';

	this->setData(newData, len);
}

StringStream::~StringStream()
{
	SAFE_DELETE(_baseStream);
}

std::string StringStream::readLine()
{
	int ext = strlen(LINE_MARK);

	char* cursor = getPtr();
	char* ptr = getPtr();

	while ((*ptr) != 0)
	{
		if ((ext - 1 >= 0) && LINE_EQUAL(ptr - ext + 1))
		{
			break;
		}
		ptr++;
	}

	if ((ext - 1 >= 0) && LINE_EQUAL(ptr - ext + 1))
	{
		ptr++;
	}
	else
	{
		ext = 0;
	}

	ss_t size = ptr - cursor;
	if ((*ptr) == 0)
	{
		this->setCursor(getCursor() + size + 1);
		return std::string(cursor, size);
	}
	else
	{
		this->setCursor(getCursor() + size);
		return std::string(cursor, size);
	}
}

void StringStream::writeString(const char* line, int size)
{
	if (line == nullptr)
	{
		return;
	}

	int newCursor = size + this->getCursor();
	if (newCursor + 1 > this->getCapacity())
	{
		char* newData = StreamHelper::mallocStream(newCursor + 1, (char*)this->getData(), this->getCapacity());
		this->setData(newData, newCursor + 1);
	}

	char* ptr = getPtr();
	memcpy(ptr, line, size);

	this->setCursor(newCursor);
}

void StringStream::writeLine(const char* line, int size)
{
	this->writeString(line, size);
	this->writeLine();
}

void StringStream::writeLine()
{
	int ext = strlen(LINE_MARK);

	int newCursor = ext + this->getCursor();
	if (newCursor + 1 > this->getCapacity())
	{
		char* newData = StreamHelper::mallocStream(newCursor + 1, (char*)this->getData(), this->getCapacity());
		this->setData(newData, newCursor + 1);
	}

	char* ptr = getPtr();
	LINE_APPEND(ptr);

	this->setCursor(newCursor);
}

bool StringStream::readEnd()
{
	return getCursor() >= getCapacity();
}
