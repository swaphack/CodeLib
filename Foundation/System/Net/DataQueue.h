#pragma once

#include "../Net/NetData.h"

#include <queue>

namespace sys
{
	// 数据队列
	class DataQueue
	{
	public:
		DataQueue();
		~DataQueue();
	public:
		void push(NetData* data);

		NetData* pop();

		NetData* top();

		int count();

		bool empty();

		void dispose();
	private:
		std::queue<NetData*> _datas;
	};
}