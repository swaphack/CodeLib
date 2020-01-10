#include "StreamReader.h"

using namespace sys;

StreamReader::StreamReader()
:Stream(new StreamBaseRef())
{

}

StreamReader::StreamReader(const char* data, ss_t size)
: Stream(new StreamBaseRef())
{
	this->setData(data, size);
}


StreamReader::~StreamReader()
{
	SAFE_DELETE(_baseStream);
}

char StreamReader::readInt8()
{
	return this->read<char>();
}

uint8_t StreamReader::readUInt8()
{
	return this->read<uint8_t>();
}

short StreamReader::readInt16()
{
	return this->read<short>();
}

uint16_t StreamReader::readUInt16()
{
	return this->read<uint16_t>();
}

int32_t StreamReader::readInt32()
{
	return this->read<int32_t>();
}

uint32_t StreamReader::readUInt32()
{
	return this->read<uint32_t>();
}

int64_t StreamReader::readInt64()
{
	return this->read<int64_t>();
}

uint64_t StreamReader::readUInt64()
{
	return this->read<uint64_t>();
}

float StreamReader::readFloat()
{
	return this->read<float>();
}

double StreamReader::readDouble()
{
	return this->read<double>();
}

char* StreamReader::readString(ss_t size)
{
	if (getCursor() + size > this->getLength())
	{
		return 0;
	}

	char* ptr = getPtr();

	setCursor(getCursor() + size);

	return ptr;
}

std::string StreamReader::readString()
{
	ss_t size = readInt32();
	char* pszText = readString(size);
	return std::string(pszText, size);
}

char* StreamReader::readRemain(ss_t& size)
{
	size = this->getLength() - this->getCursor();

	char* ptr = getPtr();

	setCursor(getCursor() + size);

	return ptr;
}
