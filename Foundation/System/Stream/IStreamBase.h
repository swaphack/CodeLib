#pragma once

#include "macros.h"

namespace sys
{
	// �����ݶ�ȡ�ӿ�
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

	// ������д��ӿ�
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

	// �����ݽӿ�
	class IStreamBase
	{
	public:
		virtual ~IStreamBase() {}
	public:
		// ������������
		virtual void setData(const char* data, ss_t size) = 0;
		// ��ȡ��������
		virtual const char* getData() const = 0;
		// ��ȡ���ݳ���
		virtual int32 getLength() const = 0;
		// �������ݳ���
		virtual void setLength(int32 length) = 0;
		// �ͷ�������
		virtual void freeStream() = 0;
	};
}