#pragma once

#include <map>

namespace sys
{
	class IResource;
	class Resource;

	enum ResourceType
	{
		ERT_LOCAL,	// ����
		ERT_REMOTE, // Զ��
	};

	// ��Դ��ʽ����
	class ResourceMgr
	{
	public:
		ResourceMgr();
		~ResourceMgr();
	public:
		// ��Դ����
		Resource* getResource(ResourceType type);
		// ���һ���µĻ�ȡ��Դ�ķ�ʽ
		void addMethod(ResourceType type, IResource* res);
		// �Ƴ����еĻ�ȡ��Դ�ķ�ʽ
		void removeMethod(ResourceType type);
	private:
		// ��ʼ��
		void init();
		// ����
		void dispose();
	private:
		// ��Դ;������
		ResourceType _resType;
		// ��Դ;������
		std::map<ResourceType, IResource*> _getResMethods;
	};
}