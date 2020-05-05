#pragma once

#include "Common/Node/ColorNode.h"

namespace render
{
	class CtrlWidget : public ColorNode
	{
	public:
		CtrlWidget();
		virtual ~CtrlWidget();
	public:
		virtual bool init();
	protected:
	private:
	};
}