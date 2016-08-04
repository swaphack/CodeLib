#pragma once

#include "LocalResource.h"
#include "RemoteResource.h"

namespace web
{
	class ResourceMgr
	{
	public:
		ResourceMgr();
		~ResourceMgr();
	public:
		// 本地资源
		LocalResource* getLocal();
		// 设置本地资源位置
		void setLocalUrl(const char* url);
		// 远程资源
		RemoteResource* getRemote();
	protected:
	private:
		// 本地资源
		LocalResource* _localRes;
		// 远程资源
		RemoteResource* _remoteRes;
	};
}