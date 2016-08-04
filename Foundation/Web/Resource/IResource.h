#pragma once

#include "../Cache/import.h"

namespace web
{
	class IResource
	{
	public:
		virtual ~IResource() {}
	public:
		// ��ʼ��
		virtual void init() = 0;
		// ����
		virtual void save() = 0;
		// ����
		virtual void dispose() = 0;
		// ����
		virtual const char* getName() = 0;
		// ����
		virtual CacheGroup* getCache() = 0;
	};
}