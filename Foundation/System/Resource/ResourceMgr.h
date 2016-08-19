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
		// 资源管理
		Resource* getResource(int type);
		// 添加一种新的获取资源的方式
		void addMethod(int type, IResource* res);
		// 移除就有的获取资源的方式
		void removeMethod(int type);
	private:
		// 初始化
		void init();
		// 销毁
		void disponse();
	private:
		// 资源途径类型
		int _resType;
		// 资源途径管理
		std::map<int, IResource*> _getResMethods;
	};
}