#pragma once

#include "Resource.h"

namespace sys
{
	enum ResourceType
	{
		ERT_LOCAL,	// 本地
		ERT_REMOTE, // 远程
	};

	class ResourceMgr
	{
	public:
		ResourceMgr();
		~ResourceMgr();
	public:
		// 设置资源途径类型
		void setResourceType(ResourceType type);
		// 获取资源途径类型
		ResourceType getResourceType();

		// 设置资源位置
		void setUrl(const char* url);
		// 资源管理
		Resource* getResource();
	private:
		// 初始化
		void init();
		// 销毁
		void disponse();
	private:
		// 资源途径类型
		ResourceType _resType;
		// 资源途径管理
		std::map<ResourceType, IResource*> _resources;
	};
}