#pragma once

#include "Common/Node/ColorNode.h"

namespace render
{
	// ����
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