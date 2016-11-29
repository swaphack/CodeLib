#include "ThreadPool.h"
#include "Thread.h"
#include <vector>

using namespace sys;


ThreadPool::ThreadPool()
{
	std::thread th = std::thread([this](){
		while (true)
		{
			this->update();
		}
	});

	th.detach();
}

ThreadPool::~ThreadPool()
{

}

ThreadPool* ThreadPool::getInstance()
{
	static ThreadPool* s_ThreadPool = nullptr;
	if (s_ThreadPool == nullptr)
	{
		s_ThreadPool = new ThreadPool();
	}

	return s_ThreadPool;
}

Thread* ThreadPool::createThread(std::function<void()> handler)
{
	Thread* pThread = new Thread();
	pThread->start(handler);
	this->add(pThread);

	return pThread;
}

void ThreadPool::add(Thread* pThread)
{
	if (pThread == nullptr)
	{
		return;
	}

	if (pThread->getID() == Thread::INVALID_THREAD_ID)
	{
		return;
	}

	printf("try add push lock\n");

	m_pMutex.lock();

	m_mThreads[pThread->getID()] = pThread;

	m_pMutex.unlock();
}

void ThreadPool::remove(size_t nThreadID)
{
	if (nThreadID == Thread::INVALID_THREAD_ID)
	{
		return;
	}

	printf("try add remove lock\n");

	m_pMutex.lock();

	m_mThreads.erase(nThreadID);

	m_pMutex.unlock();
}

void ThreadPool::update()
{
	if (!m_pMutex.tryLock())
	{
		return;
	}

	printf("try add check lock\n");

	std::vector<size_t> invialdThreadIDs;
	Threads::iterator iter = m_mThreads.begin();
	while (iter != m_mThreads.end())
	{
		if (iter->second->isFinish())
		{
			delete iter->second;

			invialdThreadIDs.push_back(iter->first);
		}

		iter++;
	}
	int count = invialdThreadIDs.size();
	for (int i = 0; i < count; i++)
	{
		this->remove(invialdThreadIDs[i]);
	}

	m_pMutex.unlock();
}
