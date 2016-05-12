#pragma once

#include "system.h"
#include "TouchProtocol.h"

#include <set>

namespace render
{
	class TouchProtocol;
	// 触摸管理
	class TouchManager
	{
	public:
		TouchManager();
		virtual ~TouchManager();
	public:
		// 添加触摸代理
		void addTouch(TouchProtocol* protocol);
		// 移除触摸代理
		void removeTouch(TouchProtocol* protocol);
		// 移除所有触摸代理
		void removeAllTouches();

		virtual bool onTouchBegan(float x, float y);
		virtual void onTouchMove(float x, float y);
		virtual void onTouchEnd(float x, float y);
	private:
		std::vector<TouchProtocol*> _touchProtocols;
		TouchProtocol* _lastTouchProtocol;
	};

	#define G_TOUCHMANAGER sys::Instance<TouchManager>::getInstance()
}