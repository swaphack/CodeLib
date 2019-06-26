#pragma once

#include "Stream.h"

namespace sys
{
	// Ð´Èë°ü
	class StreamWriter : public Stream, public IStreamWriter
	{
	public:
		StreamWriter(int32 size = STREAM_DEFAULT_SIZE);
		StreamWriter(const char* data, int32 size);
		virtual ~StreamWriter();
	public:
		void writeInt8(char data);
		void writeUInt8(uint8 data);
		void writeInt16(int16 data);
		void writeUInt16(uint16 data);
		void writeInt32(int32 data);
		void writeUInt32(uint32 data);
		void writeInt64(int64 data);
		void writeUInt64(uint64 data);
		void writeFloat(float data);
		void writeDouble(double data);
		void writeString(const char* data);
		void writeString(char* data, int32 size);
	public:
		template<typename T>
		void write(T data);

		void setCursorAndLength(ss_t pos);
	private:
		void realloct(ss_t size);
	};

	template<typename T>
	void StreamWriter::write( T data )
	{
		while ((int32)(getCursor() + sizeof(data)) > this->getCapacity())
		{
			this->realloct(2 * this->getCapacity());
		}

		*(T*)getPtr() = data;
		setCursorAndLength(getCursor() + sizeof(data));
	}
}