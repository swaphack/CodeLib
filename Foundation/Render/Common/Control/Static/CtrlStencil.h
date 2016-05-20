#pragma once

#include "macros.h"

namespace render
{
	// Ä£°å
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