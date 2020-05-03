#pragma once

#include "Stream.h"
#include "IStreamBase.h"

#include <cstdint>
#include <string>

namespace sys
{
	// ¶ÁÈ¡°ü
	class StreamReader : public Stream, public IStreamReader
	{
	public:
		StreamReader();
		StreamReader(const char* data, size_t size);
		virtual ~StreamReader();
	public:
		virtual char readInt8();
		virtual uint8_t readUInt8();
		virtual int16_t readInt16();
		virtual uint16_t readUInt16();
		virtual int32_t readInt32();
		virtual uint32_t readUInt32();
		virtual int64_t readInt64();
		virtual uint64_t readUInt64();
		virtual float readFloat();
		virtual double readDouble();
		virtual char* readString(size_t size);
		virtual char* readRemain(size_t& size);
		virtual std::string readString();
	public:
		template<typename T>
		T read();
	};

	template<typename T>
	T StreamReader::read()
	{
		if ((size_t)(getCursor() + sizeof(T)) > this->getLength())
		{
			return 0;
		}

		T t = *(T*)getPtr();
		setCursor(getCursor() + sizeof(T));

		return t;
	}
}