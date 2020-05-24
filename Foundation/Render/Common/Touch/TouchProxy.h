#pragma once

#include "Common/Node/Node.h"
#include "TouchDelegate.h"
#include <map>
#include <vector>
#include <set>

namespace render
{
	class TouchProxy : public sys::Object
	{
	public:
		TouchProxy(Node* target);
		virtual ~TouchProxy();
	public:
		// ���ö���
		void setTarget(Node* target);
		// ���ö���
		Node* getTarget();

		// ���ÿɵ����
		void setTouchEnabled(bool status);
		// �Ƿ�ɵ��
		bool isTouchEnabled();

		// �������ɵ��
		void setSwallowTouch(bool status);
		// �Ƿ����ɵ��
		bool isSwallowTouch();

		// ��������
		virtual bool onTouchBegan(float x, float y);
		virtual bool onTouchMoved(float x, float y);
		virtual bool onTouchEnded(float x, float y);

		// ��Ӵ����¼�
		void addTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler);
		// �Ƴ�ָ�����͵Ĵ����¼�
		void removeTouchDelegate(TouchType type);
		// �Ƴ����д����¼�
		void removeAllTouchDelegates();

		// ��Ӵ����¼�
		void addTouchFunc(TouchType type, TouchFunc func);
		// �Ƴ�ָ�����͵Ĵ����¼�
		void removeTouchFunc(TouchType type);
		// �Ƴ����д����¼�
		void removeAllTouchFuncs();
	protected:
		// �ɷ������¼�
		void dispatchTouchEvent(TouchType type, float x, float y, bool include = true);
	private:
		// ���ö���
		Node* _target = nullptr;
		//�ɵ��
		bool _bTouchEnabled = false;
		// ���ɵ��
		bool _bSwallowTouch = true;
		std::map<TouchType, TouchDelegate> _touchDelegates;
		std::map<TouchType, TouchFunc> _touchFuncs;
	};
}