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

char StreamReader::readChar()
{
	return this->read<char>();
}

uchar StreamReader::readUChar()
{
	return this->read<uchar>();
}

short StreamReader::readShort()
{
	return this->read<short>();
}

ushort StreamReader::readUShort()
{
	return this->read<ushort>();
}

int StreamReader::readInt()
{
	return this->read<int>();
}

uint StreamReader::readUInt()
{
	return this->read<uint>();
}

long StreamReader::readLong()
{
	return this->read<long>();
}

ulong StreamReader::readULong()
{
	return this->read<ulong>();
}

float StreamReader::readFloat()
{
	return this->read<float>();
}

double StreamReader::readDouble()
{
	return this->read<double>();
}

char* StreamReader::readString( int size )
{
	if (getCursor() + size > this->getLength())
	{
		return 0;
	}

	char* ptr = getPtr();

	setCursor(getCursor() + size);

	return ptr;
}

char* StreamReader::readRemain( int& size )
{
	size = this->getLength() - this->getCursor();

	char* ptr = getPtr();

	setCursor(getCursor() + size);

	return ptr;
}
