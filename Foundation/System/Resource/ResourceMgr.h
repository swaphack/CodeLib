#pragma once

#include "Resource.h"

namespace sys
{
	enum ResourceType
	{
		ERT_LOCAL,	// ����
		ERT_REMOTE, // Զ��
	};

	class ResourceMgr
	{
	public:
		ResourceMgr();
		~ResourceMgr();
	public:
		// ������Դ;������
		void setResourceType(ResourceType type);
		// ��ȡ��Դ;������
		ResourceType getResourceType();

		// ������Դλ��
		void setUrl(const char* url);
		// ��Դ����
		Resource* getResource();
	private:
		// ��ʼ��
		void init();
		// ����
		void disponse();
	private:
		// ��Դ;������
		ResourceType _resType;
		// ��Դ;������
		std::map<ResourceType, IResource*> _resources;
	};
}