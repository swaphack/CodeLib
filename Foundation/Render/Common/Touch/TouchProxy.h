#pragma once

#include "../Node/Node.h"
#include "TouchDelegate.h"
#include <map>
#include <vector>

namespace render
{
	class TouchProxy
	{
	public:
		TouchProxy(Node* target);
		virtual ~TouchProxy();
	public:
		void setTarget(Node* target);
		Node* getTarget();

		// 设置可点击性
		void setTouchEnabled(bool status);
		// 是否可点击
		bool isTouchEnabled();

		// 触摸处理
		bool onTouchBegan(float x, float y);
		void onTouchMove(float x, float y);
		void onTouchEnd(float x, float y);

		// 添加触摸事件
		void addTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler);
		// 移除触摸事件
		void removeTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler);
		// 移除指定类型的触摸事件
		void removeTouchEvent(TouchType type);
		// 移除所有触摸事件
		void removeAllTouchEvent();
	protected:
		// 派发触摸事件
		void dispatchTouchEvent(TouchType type, float x, float y);
	private:
		Node* _target;
		bool _bTouchEnabled;
		std::map<TouchType, std::vector<TouchDelegate>> _touchEvent;
	};
}