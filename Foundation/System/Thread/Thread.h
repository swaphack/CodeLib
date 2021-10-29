#pragma once

#include <functional>
#include <thread>

namespace sys
{
	// 线程
	class Thread
	{
	public:
		friend class ThreadPool;
		// 无效的线程id
		static const int32_t INVALID_THREAD_ID = -1;
	public:
		Thread();
		~Thread();
	public:
		// 执行
		template<class _Fn, class... _Args>
		void startWithParams(_Fn&& handler, _Args&&... _Ax);
		// 执行
		void start(const std::function<void()>& handler);
		// 剥离执行
		bool detach();
		// 堵塞执行
		bool join();
		// 停止
		bool isFinish() const;
		// 获取线程id
		int32_t getID() const;
	private:
		// 控制线程
		std::thread m_pThread;
		// 线程id
		size_t m_nID = 0;
		// 是否结束
		bool m_bFinish = false;
	};

	template<class _Fn, class... _Args>
	void Thread::startWithParams(_Fn&& handler, _Args&&... _Ax)
	{
		m_pThread = std::thread([=](_Args&&... _Bx){
			do 
			{
				handler(_Bx...);
				m_bFinish = true;
			} while (0);
		}, _Ax...);
		m_nID = m_pThread.get_id().hash();
		m_bFinish = false;
	}
}