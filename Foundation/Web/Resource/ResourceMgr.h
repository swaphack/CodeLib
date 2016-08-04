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
		// ������Դ
		LocalResource* getLocal();
		// ���ñ�����Դλ��
		void setLocalUrl(const char* url);
		// Զ����Դ
		RemoteResource* getRemote();
	protected:
	private:
		// ������Դ
		LocalResource* _localRes;
		// Զ����Դ
		RemoteResource* _remoteRes;
	};
}