#pragma once

#include "macros.h"

namespace sys
{
	// 流数据读取接口
	class IStreamReader
	{
	public:
		virtual ~IStreamReader() {}
	public:
		virtual char readInt8() = 0;
		virtual uint8 readUInt8() = 0;
		virtual int16 readInt16() = 0;
		virtual uint16 readUInt16() = 0;
		virtual int32 readInt32() = 0;
		virtual uint32 readUInt32() = 0;
		virtual int64 readInt64() = 0;
		virtual uint64 readUInt64() = 0;
		virtual float readFloat() = 0;
		virtual double readDouble() = 0;
		virtual char* readString(int32 size) = 0;
		virtual char* readRemain(int32& size) = 0;
	};

	// 流数据写入接口
	class IStreamWriter
	{
	public:
		virtual ~IStreamWriter() {}
	public:
		virtual void writeInt8(char data) = 0;
		virtual void writeUInt8(uint8 data) = 0;
		virtual void writeInt16(int16 data) = 0;
		virtual void writeUInt16(uint16 data) = 0;
		virtual void writeInt32(int32 data) = 0;
		virtual void writeUInt32(uint32 data) = 0;
		virtual void writeInt64(int64 data) = 0;
		virtual void writeUInt64(uint64 data) = 0;
		virtual void writeFloat(float data) = 0;
		virtual void writeDouble(double data) = 0;
		virtual void writeString(const char* data) = 0;
		virtual void writeString(char* data, int32 size) = 0;
	};

	// 流数据接口
	class IStreamBase
	{
	public:
		virtual ~IStreamBase() {}
	public:
		// 设置数据内容
		virtual void setData(const char* data, ss_t size) = 0;
		// 获取数据内容
		virtual const char* getData() const = 0;
		// 获取数据长度
		virtual int32 getLength() const = 0;
		// 设置数据长度
		virtual void setLength(int32 length) = 0;
		// 释放流数据
		virtual void freeStream() = 0;
	};
}