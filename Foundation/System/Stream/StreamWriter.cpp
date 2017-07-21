#include "StreamWriter.h"

#include <cstring>
#include <cstdlib>

using namespace sys;

StreamWriter::StreamWriter(int size)
:Stream(new StreamBaseRef())
{
	this->realloct(size);
}

StreamWriter::StreamWriter(const char* data, int size)
: Stream(new StreamBaseRef())
{
	this->setData(data, size);

	this->setCursorAndLength(size);
}

StreamWriter::~StreamWriter()
{
	SAFE_DELETE(_baseStream);
}

void StreamWriter::writeChar( char data )
{
	this->write<char>(data);
}

void StreamWriter::writeUChar( uchar data )
{
	this->write<uchar>(data);
}

void StreamWriter::writeShort( short data )
{
	this->write<short>(data);
}

void StreamWriter::writeUShort( ushort data )
{
	this->write<ushort>(data);
}

void StreamWriter::writeInt( int data )
{
	this->write<int>(data);
}

void StreamWriter::writeUInt( uint data )
{
	this->write<int>(data);
}

void StreamWriter::writeLong( long data )
{
	this->write<long>(data);
}

void StreamWriter::writeULong( ulong data )
{
	this->write<ulong>(data);
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
	int size = strlen(data);

	this->writeString((char*)data, size);
}

void StreamWriter::writeString( char* data, int size )
{
	while (getCursor() + size > this->getCapacity())
	{
		this->realloct(size + this->getCursor() + 1);
	}

	memcpy(getPtr(), data, size);

	setCursorAndLength(getCursor() + size);
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

