#pragma once

#include "system.h"
#include "ActionProtocol.h"

namespace render
{
	class Node;

	//class ActionManager;
	// �����ӿ�
	class Action : public sys::Object, public ActionProtocol, public sys::ITimer
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
		virtual void setTarget(Node* target);
		// �ж϶���ִ�ж����Ƿ���ͬ
		bool isEqualsTarget(const Node* target) const;

		const Node* getTarget() const;
	protected:
		// ����ִ��Ŀ��
		Node* _target;
	};

#define CREATE_ACTION(ACTION_TYPE) render::createAction<ACTION_TYPE>()

	template<typename T, typename = std::enable_if<std::is_base_of<Action, T>::value, T>::type>
	T* createAction()
	{
		T* temp = new T();

		AUTO_RELEASE_OBJECT(temp);

		return temp;
	}
}