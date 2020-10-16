#pragma once

#include "CtrlWidget.h"

namespace render
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