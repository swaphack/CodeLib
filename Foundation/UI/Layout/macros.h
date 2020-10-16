#pragma once

#include "system.h"

namespace ui
{
	/**
	*	布局方向
	*/
	enum class LayoutDirection
	{
		// 无
		NONE,
		// 垂直布局
		HORIZONTAL,
		// 水平布局
		ERTICAL,
	};

	/**
	*	留白状态
	*/
	struct MarginState
	{
		bool Top = false;
		bool Right = false;
		bool Bottom = false;
		bool Left = false;

		MarginState() {}

		MarginState(bool top, bool right, bool bottom, bool left)
			:Top(top), Right(right), Bottom(bottom), Left(left)
		{

		}
	};
}