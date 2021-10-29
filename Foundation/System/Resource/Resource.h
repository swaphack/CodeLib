#pragma once

#include <string>
#include <cstdint>

#include "Framework/Object.h"

#include "IResource.h"

namespace sys
{
	class CacheGroup;

	// 站点资源管理
	class Resource : public Object, public IResource
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
		virtual std::string getName() { return ""; }
		// 缓存
		virtual CacheGroup* getCache() const;
		// 加载文件数据
		virtual bool loadFileData(const std::string& filename, GetDataCallback handler);
	public:
		// 设置资源位置
		void setUrl(const std::string& url);
		// 获取资源位置
		const std::string& getUrl() const;

		// 设置是否使用缓存
		void setCacheEnable(bool status);
		// 是否使用缓存
		bool isCacheEnable() const;
		// 清空缓存
		void clearCache();
	protected:
		// 资源位置
		std::string _url;
		// 缓存是否可用
		bool _bCacheEnabled = false;
		// 缓存
		CacheGroup* _cache = nullptr;
	};
}