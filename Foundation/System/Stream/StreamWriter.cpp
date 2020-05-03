#include "StreamWriter.h"
#include "Base/macros.h"
#include "StreamHelper.h"
#include "StreamBase.h"
#include <cstring>
#include <cstdlib>

using namespace sys;

StreamWriter::StreamWriter(size_t size)
:Stream(new StreamBaseRef())
{
	this->realloct(size);
}

StreamWriter::StreamWriter(const char* data, size_t size)
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

void StreamWriter::writeUInt8( uint8_t data )
{
	this->write<uint8_t>(data);
}

void StreamWriter::writeInt16( short data )
{
	this->write<short>(data);
}

void StreamWriter::writeUInt16( uint16_t data )
{
	this->write<uint16_t>(data);
}

void StreamWriter::writeInt32( int32_t data )
{
	this->write<int32_t>(data);
}

void StreamWriter::writeUInt32( uint32_t data )
{
	this->write<int32_t>(data);
}

void StreamWriter::writeInt64( int64_t data )
{
	this->write<int64_t>(data);
}

void StreamWriter::writeUInt64( uint64_t data )
{
	this->write<uint64_t>(data);
}

void StreamWriter::writeFloat( float data )
{
	this->write<float>(data);
}

void StreamWriter::writeDouble( double data )
{
	this->write<double>(data);
}

void StreamWriter::writeString(char* data, size_t size)
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

void StreamWriter::setCursorAndLength(size_t pos)
{
	this->setCursor(pos);

	if (pos > this->getLength())
	{
		this->setLength(pos);
	}
}

void StreamWriter::realloct(size_t size)
{
	if (this->getStream() == nullptr)
	{
		return;
	}

	size_t len = getStream()->getLength();
	char* newData = StreamHelper::mallocStream(size, (void*)getStream()->getData(), len);

	getStream()->setData(newData, size);
	setLength(len);

	_capacity = size;
}

