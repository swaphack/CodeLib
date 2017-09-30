#pragma once

#include "macros.h"

namespace render
{
	/**
	*	∆¨∂Œ≤‚ ‘ 2d π”√
	*/
	class CtrlScissor : public Node
	{
	public:
		CtrlScissor();
		virtual ~CtrlScissor();
	public:
		virtual void draw();
		virtual void visit();
	private:
		sys::Rect makeRect();
	private:
		static int s_nScissorCount;
		static sys::Rect s_rect;
	};
}