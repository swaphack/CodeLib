#pragma once
#include "macros.h"

namespace sys
{
#define STREAM_DEFAULT_SIZE 2

	class IStreamBase;

	class Stream
	{
	public:
		Stream(IStreamBase* baseStream);
		virtual ~Stream();
	public:
		// 设置数据内容
		virtual void setData(const char* data, ss_t size);
		// 分配的内存长度
		ss_t getCapacity() const;
		// 获取数据长度
		ss_t getLength() const;
		// 获取游标位置
		ss_t getCursor() const;
		// 获取数据指针
		const char* getData() const;
		// 设置基础流,并标明是否释放旧的流数据
		void setStream(IStreamBase* baseStream, bool disponable = false);
		// 设置游标位置
		void setCursor(ss_t pos);
	protected:
		// 获取数据流
		IStreamBase* getStream() const;
		// 游标是否超出长度
		bool isOutOfLength();
		// 游标是否超出容量
		bool isOutOfCapacity();
		// 获取当前指针
		char* getPtr();
		// 设置分配的数据流内存长度
		void setCapacity(ss_t capacity);
		// 设置数据流长度
		void setLength(ss_t length);
	protected:
		// 游标
		ss_t _cursor;
		// 分配的内存长度
		ss_t _capacity;
		// 基础数据流
		IStreamBase* _baseStream;
	};
}