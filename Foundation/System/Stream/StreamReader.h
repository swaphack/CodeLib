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
		virtual char readInt8();
		virtual uint8 readUInt8();
		virtual int16 readInt16();
		virtual uint16 readUInt16();
		virtual int32 readInt32();
		virtual uint32 readUInt32();
		virtual int64 readInt64();
		virtual uint64 readUInt64();
		virtual float readFloat();
		virtual double readDouble();
		virtual char* readString(int32 size);
		virtual char* readRemain(int32& size);
	public:
		template<typename T>
		T read();
	};

	template<typename T>
	T StreamReader::read()
	{
		if ((int32)(getCursor() + sizeof(T)) > this->getLength())
		{
			return 0;
		}

		T t = *(T*)getPtr();
		setCursor(getCursor() + sizeof(T));

		return t;
	}
}