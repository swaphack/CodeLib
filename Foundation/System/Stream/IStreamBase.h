#pragma once

#include "macros.h"

#include <string>

namespace sys
{
	// 流数据读取接口
	class IStreamReader
	{
	public:
		virtual ~IStreamReader() {}
	public:
		virtual char readInt8() = 0;
		virtual uint8_t readUInt8() = 0;
		virtual int16_t readInt16() = 0;
		virtual uint16_t readUInt16() = 0;
		virtual int32_t readInt32() = 0;
		virtual uint32_t readUInt32() = 0;
		virtual int64_t readInt64() = 0;
		virtual uint64_t readUInt64() = 0;
		virtual float readFloat() = 0;
		virtual double readDouble() = 0;
		virtual char* readString(uint32_t size) = 0;
		virtual void* readRemain(uint32_t& size) = 0;
		virtual std::string readString() = 0;
	};

	// 流数据写入接口
	class IStreamWriter
	{
	public:
		virtual ~IStreamWriter() {}
	public:
		virtual void writeInt8(char data) = 0;
		virtual void writeUInt8(uint8_t data) = 0;
		virtual void writeInt16(int16_t data) = 0;
		virtual void writeUInt16(uint16_t data) = 0;
		virtual void writeInt32(int32_t data) = 0;
		virtual void writeUInt32(uint32_t data) = 0;
		virtual void writeInt64(int64_t data) = 0;
		virtual void writeUInt64(uint64_t data) = 0;
		virtual void writeFloat(float data) = 0;
		virtual void writeDouble(double data) = 0;
		virtual void writeData(const void* data, uint32_t size) = 0;
		virtual void writeString(const char* data, uint32_t size) = 0;
		virtual void writeString(const std::string& data) = 0;
	};

	// 流数据接口
	class IStreamBase
	{
	public:
		virtual ~IStreamBase() {}
	public:
		// 设置数据内容
		virtual void setData(const void* data, size_t size) = 0;
		// 获取数据内容
		virtual const char* getData() const = 0;
		// 获取数据长度
		virtual size_t getLength() const = 0;
		// 设置数据长度
		virtual void setLength(size_t length) = 0;
		// 释放流数据
		virtual void freeStream() = 0;
	};
}