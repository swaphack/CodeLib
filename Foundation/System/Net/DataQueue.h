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
		// 需手动释放NetData数据
		NetData* pop();

		NetData* top();

		int count();

		bool empty();

		void dispose();
	private:
		std::queue<NetData*> _datas;
	};
}