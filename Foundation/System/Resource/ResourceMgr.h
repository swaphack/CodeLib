#pragma once

#include <map>

namespace sys
{
	class IResource;
	class Resource;

	enum class ResourceType
	{
		LOCAL,	// 本地
		REMOTE, // 远程
	};

	// 资源方式管理
	class ResourceMgr
	{
	public:
		ResourceMgr();
		virtual ~ResourceMgr();
	public:
		// 资源管理
		Resource* getResource(ResourceType type);
		// 添加一种新的获取资源的方式
		void addMethod(ResourceType type, IResource* res);
		// 移除就有的获取资源的方式
		void removeMethod(ResourceType type);
	private:
		// 初始化
		void init();
		// 销毁
		void dispose();
	private:
		// 资源途径类型
		ResourceType _resType;
		// 资源途径管理
		std::map<ResourceType, IResource*> _getResMethods;
	};
}