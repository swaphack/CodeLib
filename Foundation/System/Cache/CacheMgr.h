#pragma once

#include "CacheIdentity.h"

#include <map>

namespace sys
{
	// �������
	class CacheMgr
	{
	private:
		CacheMgr();
		virtual ~CacheMgr();
	public:
		static int32_t getStaticID();
		static CacheMgr* getInstance();
	public:
		// ��id��ȡcache
		CacheIdentity* getCache(int32_t nID);
		// �����ƻ�ȡcache
		CacheIdentity* getCache(const char* name);
		// ���cache
		void addCache(CacheIdentity* pCache);
		// �Ƴ�cache
		void removeCache(CacheIdentity* pCache);
	private:
		// ���ƻ���
		std::map<std::string, CacheIdentity*> _nameCaches;
		// id����
		std::map<int32_t, CacheIdentity*> _idCaches;
	private:
		static int32_t s_ID;
		static CacheMgr* s_CacheMgr;
	};
}