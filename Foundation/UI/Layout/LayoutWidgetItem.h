#pragma once

#include "macros.h"

#include "LayoutItem.h"

namespace ui
{
	/**
	*	Ԫ�������Ԫ���ڽ���λ�úʹ�С�趨
	*/
	class LayoutWidgetItem : public render::Node, public LayoutItem
	{
	public:
		LayoutWidgetItem(Widget* widget);
		virtual ~LayoutWidgetItem();
	public:
	};
}