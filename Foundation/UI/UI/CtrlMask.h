#pragma once

#include "CtrlWidget.h"

namespace ui
{
	/**
	*	����
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