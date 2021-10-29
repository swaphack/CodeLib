#pragma once

#include <cstdint>
#include <map>
#include <string>

namespace sys
{
	class CacheIdentity;
	// 缓存管理
	class CacheMgr
	{
	private:
		CacheMgr();
		virtual ~CacheMgr();
	public:
		static int32_t getStaticID();
		static CacheMgr* getInstance();
	public:
		// 按id获取cache
		CacheIdentity* getCache(int32_t nID) const;
		// 按名称获取cache
		CacheIdentity* getCache(const std::string& name) const;
		// 添加cache
		void addCache(CacheIdentity* pCache);
		// 移除cache
		void removeCache(CacheIdentity* pCache);
	private:
		// 名称缓存
		std::map<std::string, CacheIdentity*> _nameCaches;
		// id缓存
		std::map<int32_t, CacheIdentity*> _idCaches;
	private:
		static int32_t s_ID;
		static CacheMgr* s_CacheMgr;
	};
}