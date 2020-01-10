#pragma once

#include "macros.h"
#include "Stream/StreamBase.h"

#include <queue>

namespace sys
{
	struct NetData
	{
	public:
		// ����
		char* data;
		// ��С
		int32_t size;
		// �α�
		int32_t pos;
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
		NetData(const char* value, int32_t size)
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
		int32_t getRemainSize()
		{
			return size - pos;
		}
		void init(const char* value, int32_t len)
		{// ����
			StreamHelper::freeStream(this->data);

			this->data = StreamHelper::mallocStream(len, (char*)value, len);
			this->size = len;
			this->pos = 0;
		}
		// ����ͷ
		void insert(const char* data, int32_t len)
		{
			char* newData = StreamHelper::mallocStream(len + size, (char*)data, len);
			memcpy(newData + len, this->data, this->size);

			this->init(newData, len + size);
		}
	};
}