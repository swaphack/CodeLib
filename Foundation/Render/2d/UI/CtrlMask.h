#pragma once

#include "Common/Node/ColorNode.h"

namespace render
{
	// узуж
	class CtrlMask : public ColorNode
	{
	public:
		CtrlMask();
		virtual ~CtrlMask();
	protected:
		virtual void drawSample();
	protected:
	};
}