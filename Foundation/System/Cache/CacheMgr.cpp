#include "CacheMgr.h"

using namespace sys;

CacheMgr* CacheMgr::s_CacheMgr = nullptr;

int CacheMgr::s_ID = 0;

CacheMgr::CacheMgr()
{

}

CacheMgr::~CacheMgr()
{

}

int CacheMgr::getStaticID()
{
	return ++s_ID;
}

CacheMgr* CacheMgr::getInstance()
{
	if (s_CacheMgr == nullptr)
	{
		s_CacheMgr = new CacheMgr();
	}
	return s_CacheMgr;
}

CacheIdentity* CacheMgr::getCache(int nID)
{
	std::map<int, CacheIdentity*>::iterator iter = _idCaches.find(nID);
	if (iter == _idCaches.end())
	{
		return nullptr;
	}
	return iter->second;
}

CacheIdentity* CacheMgr::getCache(const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}
	std::map<std::string, CacheIdentity*>::iterator iter = _nameCaches.find(name);
	if (iter == _nameCaches.end())
	{
		return nullptr;
	}
	return iter->second;
}

void CacheMgr::addCache(CacheIdentity* pCache)
{
	if (pCache == nullptr)
	{
		return;
	}

	ASSERT(strcmp(pCache->getName(), "") != 0);
	ASSERT(pCache->getID() != 0);

	std::map<std::string, CacheIdentity*>::iterator iter = _nameCaches.find(pCache->getName());

	ASSERT(iter == _nameCaches.end());

	_nameCaches[pCache->getName()] = pCache;

	_idCaches[pCache->getID()] = pCache;
}

void CacheMgr::removeCache(CacheIdentity* pCache)
{
	if (pCache == nullptr)
	{
		return;
	}

	ASSERT(strcmp(pCache->getName(), "") != 0);

	std::map<std::string, CacheIdentity*>::iterator iter = _nameCaches.find(pCache->getName());

	ASSERT(iter != _nameCaches.end());

	_nameCaches.erase(iter);

	_idCaches.erase(pCache->getID());
}