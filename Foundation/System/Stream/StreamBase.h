#pragma once

#include "../Base/Types.h"
#include "IStreamBase.h"

namespace sys
{
	// 辅助工具
	class StreamHelper
	{
	public:
		// 创建一个大小等于制定分配空间的内存
		static char* mallocStream(ss_t size);
		// 创建一个大小等于目标流的内存，并赋值
		static char* mallocStream(void* data, ss_t size);
		// 创建一个大小等于指定分配空间的内存，并复制数据
		static char* mallocStream(ss_t capacity, void* data, ss_t size);
		// 释放流
		static void freeStream(void* data);
	protected:
	private:
	};

	// 流数据基础，深度拷贝
	class StreamBase : public IStreamBase
	{
	public:
		StreamBase();
		virtual ~StreamBase();
	
	public:
		// 设置数据内容
		virtual void setData(const char* data, ss_t size);
		// 获取数据内容
		const char* getData() const;
		// 获取数据长度
		int getLength() const;
		// 设置数据长度
		void setLength(int length);
		// 释放流数据
		void freeStream();
	protected:
		// 数据长度
		ss_t _length;
		// 数据内容
		char* _data;
	};

	// 流数据引用基础，浅拷贝
	class StreamBaseRef : public IStreamBase
	{
	public:
		StreamBaseRef();
		virtual ~StreamBaseRef();
	public:
		// 设置数据内容
		virtual void setData(const char* data, ss_t size);
		// 获取数据内容
		const char* getData() const;
		// 获取数据长度
		int getLength() const;
		// 设置数据长度
		void setLength(int length);
		// 释放流数据
		void freeStream();
	protected:
		// 数据长度
		ss_t _length;
		// 数据内容
		char* _data;
	};

}