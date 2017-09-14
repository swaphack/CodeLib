#pragma once

#include "../Base/Instance.h"

#include "Object.h"
#include <set>

namespace sys
{
	class Object;
	class AutoReleasePool;

#define G_AUTORELEASEPOOL sys::Instance<sys::AutoReleasePool>::getInstance()

	// �����Զ��ͷŹ����
	// ���ü�����ֵΪ1ʱ���ᱻ�ͷ�
	class AutoReleasePool
	{
	public:
		AutoReleasePool();
		~AutoReleasePool();
	public:
		// ���Ҫ�Զ��ͷŵĶ���
		void addObject(Object* object);
		// �Ƴ��Զ��ͷŵĶ���
		void removeObject(Object* object);
		// ���
		void clear();
		// ����Զ��ͷų�
		void checkAutoRelease();
	protected:
		std::set<Object*> _objects;
	};

}