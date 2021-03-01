#pragma once

#include "TouchDelegate.h"
#include <map>
#include <vector>
#include <set>

namespace render
{
	class Node;

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

		// 设置是否裁剪
		void setClippingEnabled(bool status);
		// 是否裁剪
		bool isClippingEnabled();
	public:
		virtual bool isInFrontOf(const TouchProtocol* target) const;
	public:
		// 是否点击点落在改节点上,须重写
		virtual bool containTouchPoint(const math::Vector2& touchPoint);
	public:// 触摸处理
		virtual bool onTouchBegan(const math::Vector2& touchPoint);
		virtual bool onTouchMoved(const math::Vector2& touchPoint);
		virtual bool onTouchEnded(const math::Vector2& touchPoint);
		virtual void onTouchCanceled(const math::Vector2& touchPoint);
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
	public:
		// 派发触摸事件
		void dispatchTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include = true);
	private:
		//可点击
		bool _bTouchEnabled = false;
		// 吞噬点击
		bool _bTouchSwallowed = false;
		// 裁剪节点
		bool _bClippingEnabled = false;

		std::map<TouchType, std::vector<TouchDelegate>> _touchDelegates;
		std::map<TouchType, std::vector<TouchFunc>> _touchFuncs;
	};
}