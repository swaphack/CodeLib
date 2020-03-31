#pragma once

#include "Common/Node/Node.h"
#include "TouchDelegate.h"
#include <map>
#include <vector>

namespace render
{
	class TouchProxy : public TouchProtocol
	{
	public:
		TouchProxy(Node* target);
		virtual ~TouchProxy();
	public:
		void setTarget(Node* target);
		Node* getTarget();

		// ���ÿɵ����
		void setTouchEnabled(bool status);
		// �Ƿ�ɵ��
		bool isTouchEnabled();

		// ��������
		virtual bool onTouchBegan(float x, float y);
		virtual void onTouchMoved(float x, float y);
		virtual void onTouchEnded(float x, float y);

		// ��Ӵ����¼�
		void addTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler);
		// �Ƴ������¼�
		void removeTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler);
		// �Ƴ�ָ�����͵Ĵ����¼�
		void removeTouchEvent(TouchType type);
		// �Ƴ����д����¼�
		void removeAllTouchEvent();
	protected:
		// �ɷ������¼�
		void dispatchTouchEvent(TouchType type, float x, float y);
	private:
		Node* _target = nullptr;
		bool _bTouchEnabled = false;
		std::map<TouchType, std::vector<TouchDelegate>> _touchEvent;
	};
}