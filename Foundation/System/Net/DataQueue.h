#pragma once
#include <queue>
#include <cstdint>
namespace sys
{
	struct NetData;

	// 数据队列
	class DataQueue
	{
	public:
		DataQueue();
		~DataQueue();
	public:
		// 添加数据
		void pushData(NetData* data);
		// 需手动释放NetData数据
		NetData* popData();
		// 队列头元素
		NetData* topData();
		// 队列中元素个数
		int32_t count() const;
		// 队列是否为空
		bool empty() const;
		// 释放队列元素
		void dispose();
	private:
		std::queue<NetData*> _datas;
	};
}