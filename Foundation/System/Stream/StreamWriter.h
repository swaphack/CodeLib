#pragma once

#include "Stream.h"

namespace sys
{
	// Ð´Èë°ü
	class StreamWriter : public Stream, public IStreamWriter
	{
	public:
		StreamWriter(int size = STREAM_DEFAULT_SIZE);
		StreamWriter(const char* data, int size);
		virtual ~StreamWriter();
	public:
		void writeChar(char data);
		void writeUChar(uchar data);
		void writeShort(short data);
		void writeUShort(ushort data);
		void writeInt(int data);
		void writeUInt(uint data);
		void writeLong(long data);
		void writeULong(ulong data);
		void writeFloat(float data);
		void writeDouble(double data);
		void writeString(const char* data);
		void writeString(char* data, int size);
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
		while ((int)(getCursor() + sizeof(data)) > this->getCapacity())
		{
			this->realloct(2 * this->getCapacity());
		}

		*(T*)getPtr() = data;
		setCursorAndLength(getCursor() + sizeof(data));
	}
}