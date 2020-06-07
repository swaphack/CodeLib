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
		// 作用对象
		void setTarget(Node* target);
		// 作用对象
		Node* getTarget();
	public:
		// 设置可点击性
		void setTouchEnabled(bool status);
		// 是否可点击
		bool isTouchEnabled();
	public:
		// 设置吞噬点击
		void setSwallowTouch(bool status);
		// 是否吞噬点击
		bool isSwallowTouch();
	public:
		// 触摸处理
		virtual bool onTouchBegan(float x, float y);
		virtual bool onTouchMoved(float x, float y);
		virtual bool onTouchEnded(float x, float y);
	public:
		// 添加触摸事件
		void addTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler);
		// 移除指定类型的触摸事件
		void removeTouchDelegate(TouchType type);
		// 移除所有触摸事件
		void removeAllTouchDelegates();
	public:
		// 添加触摸事件
		void addTouchFunc(TouchType type, TouchFunc func);
		// 移除指定类型的触摸事件
		void removeTouchFunc(TouchType type);
		// 移除所有触摸事件
		void removeAllTouchFuncs();
	protected:
		// 派发触摸事件
		void dispatchTouchEvent(TouchType type, float x, float y, bool include = true);
	private:
		// 作用对象
		Node* _target = nullptr;
		//可点击
		bool _bTouchEnabled = false;
		// 吞噬点击
		bool _bSwallowTouch = true;
		// 是否点击到
		bool _bIncludeTouch = false;

		std::map<TouchType, TouchDelegate> _touchDelegates;
		std::map<TouchType, TouchFunc> _touchFuncs;
	};
}