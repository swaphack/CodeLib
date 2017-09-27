#pragma once

#include "macros.h"
#include "Stream/StreamBase.h"

#include <queue>

namespace sys
{
	struct NetData
	{
	public:
		// 数据
		char* data;
		// 大小
		int size;
		// 游标
		int pos;
	public:
		NetData()
		{
			this->data = nullptr;
			this->size = size;
			this->pos = 0;
		}
		NetData(const char* value)
			:NetData()
		{
			this->init(value, strlen(value));
		}
		NetData(const char* value, int size)
			:NetData()
		{
			this->init(value, size);
		}
		~NetData()
		{
			StreamHelper::freeStream(data);
		}
		const char* getCursorPtr()
		{
			return data + pos;
		}
		int getRemainSize()
		{
			return size - pos;
		}
		void init(const char* value, int len)
		{// 重置
			StreamHelper::freeStream(this->data);

			this->data = StreamHelper::mallocStream(len, (char*)value, len);
			this->size = len;
			this->pos = 0;
		}
		// 插入头
		void insert(const char* data, int len)
		{
			char* newData = StreamHelper::mallocStream(len + size, (char*)data, len);
			memcpy(newData + len, this->data, this->size);

			this->init(newData, len + size);
		}
	};
}