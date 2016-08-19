#pragma once

#include <string>

#include "IResource.h"

namespace sys
{
	// 站点资源管理
	class Resource : public IResource
	{
	public:
		Resource();
		virtual ~Resource();
	public:
		virtual void init();
		// 保存
		virtual void save();
		// 销毁
		virtual void dispose();
		// 名称
		virtual const char* getName() { return ""; }
		// 缓存
		virtual CacheGroup* getCache();
		// 加载文件数据
		virtual bool loadFileData(const char* filename, std::string& data);
	public:
		// 设置资源位置
		void setUrl(const char* url);
		// 获取资源位置
		const char* getUrl();

		// 设置是否使用缓存
		void setCacheEnable(bool status);
		// 是否使用缓存
		bool isCacheEnable();
		// 清空缓存
		void clearCache();
	protected:
		// 资源位置
		std::string _url;
		// 缓存是否可用
		bool _bCacheEnabled;
		// 缓存
		CacheGroup* _cache;
	};
}