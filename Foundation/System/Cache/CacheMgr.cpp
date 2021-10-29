#include "CacheMgr.h"

#include "CacheIdentity.h"

using namespace sys;

CacheMgr* CacheMgr::s_CacheMgr = nullptr;

int32_t CacheMgr::s_ID = 0;

CacheMgr::CacheMgr()
{

}

CacheMgr::~CacheMgr()
{

}

int32_t CacheMgr::getStaticID()
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

CacheIdentity* CacheMgr::getCache(int32_t nID) const
{
	auto iter = _idCaches.find(nID);
	if (iter == _idCaches.end())
	{
		return nullptr;
	}
	return iter->second;
}

CacheIdentity* CacheMgr::getCache(const std::string& name) const
{
	ASSERT(!name.empty());

	auto iter = _nameCaches.find(name);
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

	ASSERT(!pCache->getName().empty());
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

	ASSERT(!pCache->getName().empty());

	std::map<std::string, CacheIdentity*>::iterator iter = _nameCaches.find(pCache->getName());

	ASSERT(iter != _nameCaches.end());

	_nameCaches.erase(iter);

	_idCaches.erase(pCache->getID());
}