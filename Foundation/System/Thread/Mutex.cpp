#include "Mutex.h"
#include "../Base/import.h"

using namespace sys;

Mutex::Mutex()
{
	m_bLock = false;
	m_pLock = std::unique_lock<std::mutex>(m_pMutex, std::defer_lock);
}

Mutex::~Mutex()
{
	m_pLock.release();
}

void Mutex::lock()
{
	if (m_bLock == true)
	{
		return;
	}
	m_bLock = true;
	m_pLock.lock();
}

bool Mutex::tryLock()
{
	if (m_bLock == true)
	{
		return false;
	}
	m_bLock = true;
	m_bLock = m_pLock.try_lock();
	return m_bLock;
}

void Mutex::unlock()
{
	if (m_bLock == false)
	{
		return;
	}
	m_bLock = false;
	return m_pLock.unlock();
}

bool Mutex::isLock()
{
	return m_bLock;
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
