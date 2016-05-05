#pragma once

#include "macros.h"

namespace render
{
	class UINode : public Node
	{
	public:
		UINode();
		virtual ~UINode();
	public:
		// 添加触摸事件
		void addTouchHandler(TouchStatus status, RENDER_TOUCH_HANDLER handler);
		// 移除触摸事件
		void removeTouchHandler(TouchStatus status);
	private:
	};
}