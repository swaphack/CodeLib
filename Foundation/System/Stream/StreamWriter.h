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
		StreamWriter(const void* data, size_t size);
		virtual ~StreamWriter();
	public:
		virtual void writeInt8(char data);
		virtual void writeUInt8(uint8_t data);
		virtual void writeInt16(int16_t data);
		virtual void writeUInt16(uint16_t data);
		virtual void writeInt32(int32_t data);
		virtual void writeUInt32(uint32_t data);
		virtual void writeInt64(int64_t data);
		virtual void writeUInt64(uint64_t data);
		virtual void writeFloat(float data);
		virtual void writeDouble(double data);
		virtual void writeData(const void* data, uint32_t size);
		virtual void writeString(const char* data, uint32_t size);
		virtual void writeString(const std::string& data);
	public:
		template<typename T>
		void write(const T& data);

		void setCursorAndLength(size_t pos);
	private:
		void realloct(size_t size);
	};

	template<typename T>
	void StreamWriter::write(const T& data )
	{
		while ((int32_t)(getCursor() + sizeof(data)) > this->getCapacity())
		{
			this->realloct(2 * this->getCapacity());
		}

		*(T*)getPtr() = data;
		setCursorAndLength(getCursor() + sizeof(data));
	}
}