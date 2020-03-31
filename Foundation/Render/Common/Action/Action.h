#pragma once

#include "system.h"
#include "Common/struct/import.h"

namespace render
{
#define CREATE_ACTION(ACTION_TYPE) createAction<ACTION_TYPE>()

	template<typename T>
	T* createAction()
	{
		T* temp = new T();

		AUTO_RELEASE_OBJECT(temp);

		return temp;
	}

	//class ActionManager;
	// �����ӿ�
	class Action : public sys::Object, public SystemProtocol, public sys::ITimer
	{
	public:
		Action();
		virtual ~Action();
	public:
		virtual void update(float duration) {}
		// ����
		virtual void reset();
		// ��ת
		virtual void reverse() {}
		// ���ö���ִ��Ŀ��
		virtual void setTarget(sys::Object* target);
		// �ж϶���ִ�ж����Ƿ���ͬ
		bool isEqualsTarget(const sys::Object* target);
	protected:
		// ����ִ��Ŀ��
		sys::Object* _target;
		
	};
}