#pragma once

#include "macros.h"

namespace render
{
	// ģ��
	class CtrlStencil : public ColorNode
	{
	public:
		CtrlStencil();
		virtual ~CtrlStencil();
	public:
		virtual void draw();
		virtual void visit();
	};
}