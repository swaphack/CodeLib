#pragma once

#include "Mutex.h"
#include <functional>
#include <map>
#include <condition_variable>

namespace sys
{
	class Thread;
	/** 
	*	线程池
	*	添加到线程池的线程，在结束后，会自动释放
	*/
	class ThreadPool
	{
	private:
		ThreadPool();
	public:
		~ThreadPool();
	public:
		static ThreadPool* getInstance();
		// 创建一个不带参数的线程
		Thread* createThread(const std::function<void()>& handler);

		// 创建一个带参数的线程
		template<class _Fn, class... _Args>
		Thread* createThreadWithParams(_Fn&& handler, _Args&&... _Ax);

		// 添加一个新线程
		void add(Thread* pThread);
		// 移除一个已有的线程
		void remove(size_t nThreadID);
	protected:
		void update();
	private:
		typedef std::map<size_t, Thread*> Threads;
		// 线程集合
		Threads m_mThreads;
		// 增加互斥锁
		MultMutex m_pMutex;
	};

	template<class _Fn, class... _Args>
	Thread* ThreadPool::createThreadWithParams(_Fn&& handler, _Args&&... _Ax)
	{
		Thread* pThread = new Thread();
		pThread->startWithParams(handler, _Ax...);
		this->add(pThread);

		return pThread;
	}

}