#pragma once

#include "mathlib.h"

namespace ui
{
	class AutoResizeProtocol
	{
	public:
		virtual ~AutoResizeProtocol() {}
	public:
		/**
		*	当窗口位置和大小发生改变时
		*/
		virtual void resize(const math::Size& size) {};
	};
}
