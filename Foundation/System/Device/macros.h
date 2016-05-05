#pragma once

#include "../Framework/Object.h"

namespace sys
{
	// 按钮状态
	enum ButtonStatus
	{
		// 按下按钮
		EBS_BUTTON_DOWN,
		// 放开按钮
		EBS_BUTTON_UP,
	};

	// 滚轮事件
	enum ScrollEvent
	{
		// 向上滑动滚轮
		ESE_SCORLL_UP,
		// 向下滑动滚轮
		ESE_SCORLL_DOWN,
	};

	// 鼠标键
	enum MouseKey
	{
		// 左按钮
		EMK_LEFTBUTTON,
		// 滚轮
		EMK_SCROLLBUTTON,
		// 右按钮
		EMK_RIGHTBUTTON,
	};

	// 按键
	enum BoardKey
	{
		EBK_1,
	};
}

