#pragma once

#include "CtrlWidget.h"

namespace ui
{
	/**
	*	узуж
	*/
	class CtrlMask : public CtrlWidget
	{
	public:
		CtrlMask();
		virtual ~CtrlMask();
	public:
		virtual bool init();
	};
}