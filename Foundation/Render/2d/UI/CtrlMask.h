#pragma once

#include "CtrlWidget.h"

namespace render
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