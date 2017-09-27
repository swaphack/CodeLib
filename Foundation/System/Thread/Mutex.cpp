#include "Mutex.h"
#include "Base/import.h"

using namespace sys;

Mutex::Mutex()
{
	m_pLock = std::unique_lock<std::mutex>(m_pMutex, std::defer_lock);
}

Mutex::~Mutex()
{
}

void Mutex::lock(const std::string& msg)
{
	m_pLock.lock();
	PRINT(msg.c_str());
}

bool Mutex::tryLock(const std::string& msg)
{
	bool bRet = m_pLock.try_lock();
	PRINT(msg.c_str());
	return bRet;
}

void Mutex::unlock(const std::string& msg)
{
	m_pLock.unlock();
	PRINT(msg.c_str());
}

//////////////////////////////////////////////////////////////////////////
MultMutex::MultMutex()
{
	m_nLockCount = 0;
	m_pLock = std::unique_lock<std::recursive_mutex>(m_pMutex, std::defer_lock);
}

MultMutex::~MultMutex()
{

}

void MultMutex::lock()
{
	m_pMutex.lock();
	m_nLockCount++;
}

bool MultMutex::tryLock()
{
	bool bRet = m_pMutex.try_lock();
	if (bRet)
	{
		m_nLockCount++;
	}

	return bRet;
}

void MultMutex::unlock()
{
	m_pLock.unlock();
	m_nLockCount--;
}

bool MultMutex::isLock()
{
	return m_nLockCount != 0;
}
