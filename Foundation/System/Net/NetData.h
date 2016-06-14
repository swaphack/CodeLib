#pragma once

#include "macros.h"
#include "../Stream/StreamBase.h"

#include <queue>

namespace sys
{
	struct NetData
	{
	public:
		char* data;
		int size;
		int pos;
	public:
		NetData()
		{
			this->data = nullptr;
			this->size = size;
			this->pos = 0;
		}
		NetData(const char* data)
		{
			this->init(data, strlen(data));
		}
		NetData(const char* data, int size)
		{
			this->init(data, size);
		}
		void init(const char* data, int size)
		{
 			int len = size * sizeof(char);

			this->data = StreamHelper::mallocStream(len, (char*)data, size);

			this->size = size;
			this->pos = 0;
		}
		~NetData()
		{
			StreamHelper::freeStream(data);
		}
	};
}