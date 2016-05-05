#pragma once

#include "../../Common/common.h"

namespace render
{
	// 触摸状态
	enum TouchStatus
	{
		ETS_NONE,	// 未触摸
		ETS_DOWN,	// 按下	
		EST_ON,		// 按住不放
		ETS_UP,		// 放手
	};

	typedef bool (Node::*RENDER_TOUCH_HANDLER)(Node*, sys::Point*);
}