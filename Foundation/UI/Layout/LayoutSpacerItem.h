#pragma once

#include "macros.h"

#include "LayoutWidgetItem.h"

namespace ui
{
	// 方向
	enum Orientation
	{
		// 水平
		EO_Horizontal,
		// 垂直
		EO_Vertial,
	};

	/**
	*	空置项，用于填充
	*/
	class LayoutSpacerItem : public render::Node, public LayoutItem
	{
	public:
		LayoutSpacerItem();
		virtual ~LayoutSpacerItem();
	public:
		/**
		*	设置空置项方向
		*/
		void setOrientation(Orientation eType);
		/**
		*	获取空置项方向
		*/
		Orientation getOrientation();
	protected:
		// 空置项方向
		Orientation m_eOrientation;
	};
}