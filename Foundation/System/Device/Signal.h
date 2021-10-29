#pragma once

namespace sys
{
	// 信号
	class Signal
	{
	public:
		Signal();
		virtual ~Signal();
	public:
		// 设置消息
		virtual void setMessage(void* msg);
		// 获取消息
		virtual void* getMessage() const;
	private:
		void* _msg = nullptr;
	};
}