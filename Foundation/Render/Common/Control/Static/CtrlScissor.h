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
	protected:
	private:
	};
}