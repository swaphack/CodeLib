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
		// ��Դ����
		Resource* getResource(int type);
		// ���һ���µĻ�ȡ��Դ�ķ�ʽ
		void addMethod(int type, IResource* res);
		// �Ƴ����еĻ�ȡ��Դ�ķ�ʽ
		void removeMethod(int type);
	private:
		// ��ʼ��
		void init();
		// ����
		void disponse();
	private:
		// ��Դ;������
		int _resType;
		// ��Դ;������
		std::map<int, IResource*> _getResMethods;
	};
}