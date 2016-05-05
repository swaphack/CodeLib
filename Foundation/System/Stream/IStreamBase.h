#pragma once

#include "../Base/import.h"

namespace sys
{
	// ���������ݴ�С����
	typedef long ss_t;

	// �����ݶ�ȡ�ӿ�
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

	// ������д��ӿ�
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
		virtual int getLength() const = 0;
		// �������ݳ���
		virtual void setLength(int length) = 0;
		// �ͷ�������
		virtual void freeStream() = 0;
	};
}