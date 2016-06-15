#pragma once

#include "system.h"
#include "TouchProxy.h"

#include <set>

namespace render
{
	class Node;
	class TouchProxy;
	// 触摸管理
	class TouchManager
	{
	public:
		TouchManager();
		virtual ~TouchManager();
	public:
		// 添加触摸代理
		void addTouch(TouchProxy* protocol);
		// 移除触摸代理
		void removeTouch(TouchProxy* protocol);
		// 移除所有触摸代理
		void removeAllTouches();

		bool onTouchBegan(float x, float y);
		void onTouchMove(float x, float y);
		void onTouchEnd(float x, float y);
	private:
		std::vector<TouchProxy*> _touchProtocols;
		TouchProxy* _lastTouchProtocol;
	};

	#define G_TOUCHMANAGER sys::Instance<TouchManager>::getInstance()
}