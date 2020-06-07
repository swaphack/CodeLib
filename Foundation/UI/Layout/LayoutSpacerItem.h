#pragma once

#include "LayoutItemEx.h"

namespace ui
{
	// 方向
	enum SpacerOrientation
	{
		// 水平
		ESO_Horizontal,
		// 垂直
		ESO_Vertial,
	};

	/**
	*	空置项，用于填充
	*/
	class LayoutSpacerItem : public LayoutItemEx
	{
	public:
		LayoutSpacerItem();
		virtual ~LayoutSpacerItem();
	public:
		/**
		*	设置空置项方向
		*/
		void setOrientation(SpacerOrientation eType);
		/**
		*	获取空置项方向
		*/
		SpacerOrientation getOrientation();
	protected:
		// 空置项方向
		SpacerOrientation m_eOrientation;
	};
}