#pragma once

#include "../Net/NetData.h"

#include <queue>

namespace sys
{
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
	protected:
	private:
		std::queue<NetData*> _datas;
	};
}