#include "Thread.h"
#include "ThreadPool.h"

using namespace sys;

Thread::Thread()
{
	m_bFinish = true;
	m_nID = INVALID_THREAD_ID;
}

Thread::~Thread()
{
}

void Thread::start(std::function<void()> handler)
{
	m_pThread = std::thread([=](){
		do
		{
			handler();
			
			m_bFinish = true;
		} while (0);
	});
	m_nID = m_pThread.get_id().hash();
	m_bFinish = false;
}

bool Thread::detach()
{
	if (m_bFinish == true || m_nID == INVALID_THREAD_ID)
	{
		return false;
	}
	m_pThread.detach();
	return true;
}

bool Thread::join()
{
	if (m_bFinish == true || m_nID == INVALID_THREAD_ID)
	{
		return false;
	}
	if (m_pThread.joinable())
	{
		m_pThread.join();
		return true;
	}

	return false;
}

bool Thread::isFinish()
{
	return m_bFinish;
}

int Thread::getID()
{
	return m_nID;
}