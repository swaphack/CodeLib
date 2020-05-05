#pragma once

#include "LayoutItemEx.h"

namespace ui
{
	/**
	*	元件项，用于元件在界面位置和大小设定
	*/
	class LayoutWidgetItem : public LayoutItemEx
	{
	public:
		LayoutWidgetItem(render::CtrlWidget* widget);
		virtual ~LayoutWidgetItem();
	public:
	};
}