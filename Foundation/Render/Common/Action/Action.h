#pragma once

#include "system.h"
#include "../GL/import.h"

namespace render
{
	//class ActionManager;
	// �����ӿ�
	class Action : public SystemProtocol, public sys::ITimer
	{
	public:
		Action();
		virtual ~Action();
	public:
		virtual void update(float duration) {}
		// ���ö���ִ��Ŀ��
		void setTarget(sys::Object* target);		
		// �ж϶���ִ�ж����Ƿ���ͬ
		bool isEqualsTarget(const sys::Object* target);
	protected:
		// ����ִ��Ŀ��
		sys::Object* _target;
		
	};
}