#pragma once

#include "macros.h"

namespace render
{
	// ����
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