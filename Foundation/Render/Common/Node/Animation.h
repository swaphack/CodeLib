#pragma once

#include "Node.h"

namespace render
{
	// 动画
	class Animation : public Node
	{
	public:
		Animation();
		virtual ~Animation();
	public:
		// 开始
		void start();
		// 恢复
		void pause();
		// 暂停
		void resume();
		// 结束
		void stop();

		// 定时更新事件,不要修改
		virtual void update(float interval);
	protected:
		// 添加定时器
		void registerScheduler();
		// 移除定时器
		void unregisterScheduler();
		// 定时更新事件
		virtual void updateSelf(float interval);
	private:
		// 定时器
		Scheduler* _scheduler;
	};
}