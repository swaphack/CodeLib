#include "StreamWriter.h"

#include <cstring>
#include <cstdlib>

using namespace sys;

StreamWriter::StreamWriter(ss_t size)
:Stream(new StreamBaseRef())
{
	this->realloct(size);
}

StreamWriter::StreamWriter(const char* data, ss_t size)
: Stream(new StreamBaseRef())
{
	this->setData(data, size);

	this->setCursorAndLength(size);
}

StreamWriter::~StreamWriter()
{
	SAFE_DELETE(_baseStream);
}

void StreamWriter::writeInt8( char data )
{
	this->write<char>(data);
}

void StreamWriter::writeUInt8( uint8 data )
{
	this->write<uint8>(data);
}

void StreamWriter::writeInt16( short data )
{
	this->write<short>(data);
}

void StreamWriter::writeUInt16( uint16 data )
{
	this->write<uint16>(data);
}

void StreamWriter::writeInt32( int32 data )
{
	this->write<int32>(data);
}

void StreamWriter::writeUInt32( uint32 data )
{
	this->write<int32>(data);
}

void StreamWriter::writeInt64( int64 data )
{
	this->write<int64>(data);
}

void StreamWriter::writeUInt64( uint64 data )
{
	this->write<uint64>(data);
}

void StreamWriter::writeFloat( float data )
{
	this->write<float>(data);
}

void StreamWriter::writeDouble( double data )
{
	this->write<double>(data);
}

void StreamWriter::writeString(const char* data )
{
	int32 size = strlen(data);

	this->writeString((char*)data, size);
}

void StreamWriter::writeString(char* data, ss_t size)
{
	while (getCursor() + size > this->getCapacity())
	{
		this->realloct(size + this->getCursor() + 1);
	}

	memcpy(getPtr(), data, size);

	setCursorAndLength(getCursor() + size);
}

void StreamWriter::writeString(const std::string& data)
{
	this->writeInt32(data.size());
	this->writeString((char*)data.c_str(), data.size());
}

void StreamWriter::setCursorAndLength(ss_t pos)
{
	this->setCursor(pos);

	if (pos > this->getLength())
	{
		this->setLength(pos);
	}
}

void StreamWriter::realloct(ss_t size)
{
	if (this->getStream() == nullptr)
	{
		return;
	}

	ss_t len = getStream()->getLength();
	char* newData = StreamHelper::mallocStream(size, (void*)getStream()->getData(), len);

	getStream()->setData(newData, size);
	setLength(len);

	_capacity = size;
}

