#pragma once

#include "Base/Instance.h"
#include <set>
#include <functional>

namespace sys
{
	class Object;

	// �����Զ��ͷŹ����
	// ���ü�����ֵΪ1ʱ���ᱻ�ͷ�
	class AutoReleasePool
	{
	public:
		AutoReleasePool();
		virtual ~AutoReleasePool();
	public:
		// ���Ҫ�Զ��ͷŵĶ���
		void addObject(Object* object);
		// �Ƴ��Զ��ͷŵĶ���
		void removeObject(Object* object);
		// ���
		void clear();
		// ����Զ��ͷų�
		void checkAutoRelease();
	public:
		void startThread(const std::function<void()>& func);
		void endThread();
	protected:
		std::set<Object*> _objects;
		// �߳���
		uint32_t _threadCount = 0;
	};

	#define G_AUTORELEASEPOOL Instance<AutoReleasePool>::getInstance()
}