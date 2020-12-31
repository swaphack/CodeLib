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
		// 设置可点击性
		void setTouchEnabled(bool status);
		// 是否可点击
		bool isTouchEnabled();
	public:
		// 设置吞噬点击
		void setTouchSwallowed(bool status);
		// 是否吞噬点击
		bool isTouchSwallowed();
	public:
		// 是否点击点落在改节点上,须重写
		virtual bool containTouchPoint(const math::Vector2& touchPoint);
		// 吞噬处理,须重写
		virtual void doSwallowTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include = true);
		// 非吞噬处理,须重写
		virtual void doNotSwallowTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include = true);
	public:
		// 触摸处理
		virtual bool onTouchBegan(const math::Vector2& touchPoint);
		virtual bool onTouchMoved(const math::Vector2& touchPoint);
		virtual bool onTouchEnded(const math::Vector2& touchPoint);
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
		void dispatchTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include = true);
		// 派发吞噬事件
		void dispatchSwallowEvent(TouchType type, const math::Vector2& touchPoint, bool include = true);
	private:
		//可点击
		bool _bTouchEnabled = false;
		// 吞噬点击
		bool _bTouchSwallowed = false;
		// 是否点击到
		bool _bIncludeTouch = false;

		std::map<TouchType, TouchDelegate> _touchDelegates;
		std::map<TouchType, TouchFunc> _touchFuncs;
	};
}