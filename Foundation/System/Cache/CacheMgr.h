#pragma once

#include "CacheIdentity.h"

#include <map>

namespace sys
{
	// 缓存管理
	class CacheMgr
	{
	private:
		CacheMgr();
		virtual ~CacheMgr();
	public:
		static int getStaticID();
		static CacheMgr* getInstance();
	public:
		// 按id获取cache
		CacheIdentity* getCache(int nID);
		// 按名称获取cache
		CacheIdentity* getCache(const char* name);
		// 添加cache
		void addCache(CacheIdentity* pCache);
		// 移除cache
		void removeCache(CacheIdentity* pCache);
	private:
		// 名称缓存
		std::map<std::string, CacheIdentity*> _nameCaches;
		// id缓存
		std::map<int, CacheIdentity*> _idCaches;
	private:
		static int s_ID;
		static CacheMgr* s_CacheMgr;
	};
}