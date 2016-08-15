#include "CacheIdentity.h"

#include "CacheMgr.h"

using namespace web;

CacheIdentity::CacheIdentity()
{
	_id = 0;
	_bInCacheControl = false;
}

CacheIdentity::~CacheIdentity()
{
	if (_bInCacheControl)
	{
		CacheMgr::getInstance()->removeCache(this);
	}
}

int CacheIdentity::getID()
{
	return _id;
}

void CacheIdentity::setInControl(bool status)
{
	if (_bInCacheControl == status)
	{
		return;
	}
	_bInCacheControl = status;
	if (_bInCacheControl)
	{
		this->makeID();
		CacheMgr::getInstance()->addCache(this);
	}
	else
	{
		CacheMgr::getInstance()->removeCache(this);
	}
}

bool CacheIdentity::isInControl()
{
	return _bInCacheControl;
}

void CacheIdentity::makeID()
{
	if (_id == 0)
	{
		_id = CacheMgr::getInstance()->getStaticID();
	}
}
