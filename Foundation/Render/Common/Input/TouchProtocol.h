#pragma once

#include "TouchDelegate.h"
#include <map>
#include <vector>
#include <set>

namespace render
{
	class TouchProtocol
	{
	public:
		TouchProtocol();
		virtual ~TouchProtocol();
	public:
		// ���ÿɵ����
		void setTouchEnabled(bool status);
		// �Ƿ�ɵ��
		bool isTouchEnabled();
	public:
		// �������ɵ��
		void setTouchSwallowed(bool status);
		// �Ƿ����ɵ��
		bool isTouchSwallowed();
	public:
		// �Ƿ��������ڸĽڵ���,����д
		virtual bool containTouchPoint(const math::Vector2& touchPoint);
		// ���ɴ���,����д
		virtual void doSwallowTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include = true);
		// �����ɴ���,����д
		virtual void doNotSwallowTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include = true);
	public:
		// ��������
		virtual bool onTouchBegan(const math::Vector2& touchPoint);
		virtual bool onTouchMoved(const math::Vector2& touchPoint);
		virtual bool onTouchEnded(const math::Vector2& touchPoint);
	public:
		// ��Ӵ����¼�
		void addTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler);
		// �Ƴ�ָ�����͵Ĵ����¼�
		void removeTouchDelegate(TouchType type);
		// �Ƴ����д����¼�
		void removeAllTouchDelegates();
	public:
		// ��Ӵ����¼�
		void addTouchFunc(TouchType type, TouchFunc func);
		// �Ƴ�ָ�����͵Ĵ����¼�
		void removeTouchFunc(TouchType type);
		// �Ƴ����д����¼�
		void removeAllTouchFuncs();
	protected:
		// �ɷ������¼�
		void dispatchTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include = true);
		// �ɷ������¼�
		void dispatchSwallowEvent(TouchType type, const math::Vector2& touchPoint, bool include = true);
	private:
		//�ɵ��
		bool _bTouchEnabled = false;
		// ���ɵ��
		bool _bTouchSwallowed = false;
		// �Ƿ�����
		bool _bIncludeTouch = false;

		std::map<TouchType, TouchDelegate> _touchDelegates;
		std::map<TouchType, TouchFunc> _touchFuncs;
	};
}