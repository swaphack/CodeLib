#pragma once

#include "IStreamBase.h"
#include "Memory/MemoryPointer.h"
#include "Memory/MemoryData.h"

#include <cstring>

namespace sys
{
	// 流数据基础，深度拷贝
	class StreamBase : public IStreamBase
	{
	public:
		StreamBase();
		virtual ~StreamBase();
	public:
		// 设置数据内容
		virtual void setData(const char* data, size_t size);
		// 获取数据内容
		const char* getData() const;
		// 获取数据长度
		size_t getLength() const;
		// 设置数据长度
		void setLength(size_t length);
		// 释放流数据
		void freeStream();
	protected:
		MemoryData _memoryData;
	};

	// 流数据引用基础，浅拷贝
	class StreamBaseRef : public IStreamBase
	{
	public:
		StreamBaseRef();
		virtual ~StreamBaseRef();
	public:
		// 设置数据内容
		virtual void setData(const char* data, size_t size);
		// 获取数据内容
		const char* getData() const;
		// 获取数据长度
		size_t getLength() const;
		// 设置数据长度
		void setLength(size_t length);
		// 释放流数据
		void freeStream();
	protected:
		/**
		*	长度
		*/
		size_t _length = 0;
		/**
		*	数据
		*/
		char* _data = nullptr;
	};

}