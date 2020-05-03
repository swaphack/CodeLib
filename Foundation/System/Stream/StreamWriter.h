#pragma once

#include "Stream.h"
#include "IStreamBase.h"

#include <string>

namespace sys
{
	// Ð´Èë°ü
	class StreamWriter : public Stream, public IStreamWriter
	{
	public:
		StreamWriter(size_t size = STREAM_DEFAULT_SIZE);
		StreamWriter(const char* data, size_t size);
		virtual ~StreamWriter();
	public:
		void writeInt8(char data);
		void writeUInt8(uint8_t data);
		void writeInt16(int16_t data);
		void writeUInt16(uint16_t data);
		void writeInt32(int32_t data);
		void writeUInt32(uint32_t data);
		void writeInt64(int64_t data);
		void writeUInt64(uint64_t data);
		void writeFloat(float data);
		void writeDouble(double data);
		void writeString(char* data, uint32_t size);
		void writeString(const std::string& data);
	public:
		template<typename T>
		void write(T data);

		void setCursorAndLength(size_t pos);
	private:
		void realloct(size_t size);
	};

	template<typename T>
	void StreamWriter::write( T data )
	{
		while ((int32_t)(getCursor() + sizeof(data)) > this->getCapacity())
		{
			this->realloct(2 * this->getCapacity());
		}

		*(T*)getPtr() = data;
		setCursorAndLength(getCursor() + sizeof(data));
	}
}