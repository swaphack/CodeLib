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
		NetData(char* data, int size)
		{
			this->init(data, size);
		}
		void init(char* data, int size)
		{
 			int len = size * sizeof(char);
// 			this->data = (char*)malloc(len);
// 			memset(this->data, 0, len);
// 			memcpy(this->data, data, len);

			this->data = StreamHelper::mallocStream(len, data, size);

			this->size = size;
			this->pos = 0;
		}
		~NetData()
		{
			StreamHelper::freeStream(data);
		}
	};
}