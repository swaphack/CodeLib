#pragma once

#include "CtrlWidget.h"

namespace render
{
	// узуж
	class CtrlMask : public CtrlWidget
	{
	public:
		CtrlMask();
		virtual ~CtrlMask();
	protected:
		virtual void drawSample();
	protected:
	};
}