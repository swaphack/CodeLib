#include "StringStream.h"

using namespace sys;


StringStream::StringStream() 
:Stream(new StreamBaseRef())
{

}

StringStream::StringStream(const char* text)
: Stream(new StreamBaseRef())
{
	this->initWithText(text);
}

StringStream::StringStream(const char* text, int size)
: Stream(new StreamBaseRef())
{
	this->initWithText(text, size);
}

StringStream::~StringStream()
{
	SAFE_DELETE(_baseStream);
}

void StringStream::initWithText(const char* text)
{
	this->initWithText(text, strlen(text));
}

void StringStream::initWithText(const char* text, int size)
{
	int len = size + 1;

	char* newData = StreamHelper::mallocStream((void*)text, len);

	this->setData(newData, len);
}

void StringStream::readLine(std::string& text)
{
	text.clear();

	int ext = strlen(LINE_MARK);

	char* cursor = getPtr();
	if (*cursor == 0)
	{
		return;
	}
	char* ptr = getPtr();

	while ((*ptr) != 0)
	{
		if (LINE_EQUAL(ptr - ext + 1))
		{
			break;
		}
		ptr++;
	}

	if (LINE_EQUAL(ptr - ext + 1))
	{
		ptr++;
	}

	ss_t size = ptr - cursor;
	if ((*ptr) == 0)
	{
		this->setCursor(getCursor() + size);
	}
	else
	{
		this->setCursor(getCursor() + size);
	}

	text = std::string(cursor, size);
}

void StringStream::readRemain(std::string& text)
{
	text.clear();
	text = std::string(this->getData() + this->getCursor(), this->getCapacity() - this->getCursor() - 1);
	this->setCursor(this->getCapacity() - 1);
}

void StringStream::writeString(const char* line, int size)
{
	if (line == nullptr)
	{
		return;
	}

	int newCursor = size + this->getCursor();
	if (newCursor > this->getCapacity() - 1)
	{
		char* newData = StreamHelper::mallocStream(newCursor + 1, (char*)this->getData(), this->getCapacity());
		this->setData(newData, newCursor + 1);
	}

	char* ptr = getPtr();
	memcpy(ptr, line, size);

	this->setCursor(newCursor);
}

void StringStream::writeString(const std::string& text)
{
	writeString(text.c_str(), text.size());
}

void StringStream::writeLine(const char* line, int size)
{
	this->writeString(line, size);
	this->writeLine();
}

void StringStream::writeLine(const std::string& text)
{
	writeLine(text.c_str(), text.size());
}

void StringStream::writeLine()
{
	int ext = strlen(LINE_MARK);

	int newCursor = ext + this->getCursor();
	if (newCursor > this->getCapacity() - 1)
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
