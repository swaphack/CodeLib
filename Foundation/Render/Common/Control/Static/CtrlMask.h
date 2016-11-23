#pragma once

#include "macros.h"

namespace render
{
	// узуж
	class CtrlMask : public ColorNode
	{
	public:
		CtrlMask();
		virtual ~CtrlMask();
	public:
		virtual void draw();
	protected:
	};
}