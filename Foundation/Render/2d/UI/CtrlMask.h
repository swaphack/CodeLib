#pragma once

#include "CtrlWidget.h"

namespace render
{
	// ����
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