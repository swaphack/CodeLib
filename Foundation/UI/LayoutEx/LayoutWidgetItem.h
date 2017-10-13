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
		LayoutWidgetItem(Widget* widget);
		virtual ~LayoutWidgetItem();
	public:
	};
}