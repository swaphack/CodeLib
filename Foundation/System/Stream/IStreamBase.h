#pragma once

#include "../Base/import.h"

namespace sys
{
	// 定义流数据大小类型
	typedef long ss_t;

	// 流数据读取接口
	class IStreamReader
	{
	public:
		virtual ~IStreamReader() {}
	public:
		virtual char readChar() = 0;
		virtual uchar readUChar() = 0;
		virtual short readShort() = 0;
		virtual ushort readUShort() = 0;
		virtual int readInt() = 0;
		virtual uint readUInt() = 0;
		virtual long readLong() = 0;
		virtual ulong readULong() = 0;
		virtual float readFloat() = 0;
		virtual double readDouble() = 0;
		virtual char* readString(int size) = 0;
		virtual char* readRemain(int& size) = 0;
	};

	// 流数据写入接口
	class IStreamWriter
	{
	public:
		virtual ~IStreamWriter() {}
	public:
		virtual void writeChar(char data) = 0;
		virtual void writeUChar(uchar data) = 0;
		virtual void writeShort(short data) = 0;
		virtual void writeUShort(ushort data) = 0;
		virtual void writeInt(int data) = 0;
		virtual void writeUInt(uint data) = 0;
		virtual void writeLong(long data) = 0;
		virtual void writeULong(ulong data) = 0;
		virtual void writeFloat(float data) = 0;
		virtual void writeDouble(double data) = 0;
		virtual void writeString(const char* data) = 0;
		virtual void writeString(char* data, int size) = 0;
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
		virtual int getLength() const = 0;
		// 设置数据长度
		virtual void setLength(int length) = 0;
		// 释放流数据
		virtual void freeStream() = 0;
	};
}