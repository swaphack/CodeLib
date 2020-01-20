#include "StringStream.h"
#include "Base/macros.h"

using namespace sys;


StringStream::StringStream() 
:Stream(new StreamBaseRef())
{

}

StringStream::StringStream(const std::string& text)
: Stream(new StreamBaseRef())
{
	this->initWithText(text);
}

StringStream::StringStream(const char* text, int32_t size)
: Stream(new StreamBaseRef())
{
	this->initWithText(text, size);
}

StringStream::~StringStream()
{
	SAFE_DELETE(_baseStream);
}

void StringStream::initWithText(const std::string& text)
{
	this->initWithText(text.c_str(), text.size());
}

void StringStream::initWithText(const char* text, int32_t size)
{
	int32_t len = size;

	char* newData = StreamHelper::mallocStream((void*)text, len);

	this->setData(newData, len);
}

void StringStream::readLine(std::string& text)
{
	text.clear();

	int32_t ext = strlen(LINE_MARK);

	char* cursor = getPtr();
	if (*cursor == NULL)
	{
		return;
	}
	char* ptr = getPtr();

	while (ptr - getData() < getCapacity())
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

	this->setCursor(getCursor() + size);

	text = std::string(cursor, size);
}

void StringStream::readRemain(std::string& text)
{
	text.clear();
	text = std::string(this->getData() + this->getCursor(), this->getCapacity() - this->getCursor());
	this->setCursor(this->getCapacity());
}

void StringStream::writeString(const char* line, int32_t size)
{
	if (line == nullptr)
	{
		return;
	}

	int32_t newCursor = size + this->getCursor();
	if (newCursor > this->getCapacity())
	{
		char* newData = StreamHelper::mallocStream(newCursor, (char*)this->getData(), this->getCapacity());
		this->setData(newData, newCursor);
	}

	char* ptr = getPtr();
	memcpy(ptr, line, size);

	this->setCursor(newCursor);
}

void StringStream::writeString(const std::string& text)
{
	writeString(text.c_str(), text.size());
}

void StringStream::writeLine(const char* line, int32_t size)
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
	int32_t ext = strlen(LINE_MARK);
	this->writeString(LINE_MARK, ext);
}

bool StringStream::readEnd()
{
	return getCursor() >= getCapacity();
}
