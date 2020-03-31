#pragma once

#include "system.h"
#include "Common/Touch/TouchDelegate.h"
#include <vector>

namespace render
{
	class Node;
	class TouchProxy;
	// 触摸管理
	class TouchManager : public TouchProtocol
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
		void onTouchMoved(float x, float y);
		void onTouchEnded(float x, float y);
	private:
		std::vector<TouchProxy*> _touchProtocols;
		TouchProxy* _lastTouchProtocol;
	};

	#define G_TOUCHMANAGER sys::Instance<TouchManager>::getInstance()
}