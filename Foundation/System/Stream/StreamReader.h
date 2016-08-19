#pragma once

#include "Stream.h"

namespace sys
{
	// ¶ÁÈ¡°ü
	class StreamReader : public Stream, public IStreamReader
	{
	public:
		StreamReader();
		StreamReader(const char* data, ss_t size);
		virtual ~StreamReader();
	public:
		virtual char readChar();
		virtual uchar readUChar();
		virtual short readShort();
		virtual ushort readUShort();
		virtual int readInt();
		virtual uint readUInt();
		virtual long readLong();
		virtual ulong readULong();
		virtual float readFloat();
		virtual double readDouble();
		virtual char* readString(int size);
		virtual char* readRemain(int& size);
	public:
		template<typename T>
		T read();
	};

	template<typename T>
	T StreamReader::read()
	{
		if ((int)(getCursor() + sizeof(T)) > this->getLength())
		{
			return 0;
		}

		T t = *(T*)getPtr();
		setCursor(getCursor() + sizeof(T));

		return t;
	}
}