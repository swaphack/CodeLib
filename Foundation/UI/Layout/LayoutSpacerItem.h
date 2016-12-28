#pragma once

#include "macros.h"

#include "LayoutWidgetItem.h"

namespace ui
{
	// ����
	enum Orientation
	{
		// ˮƽ
		EO_Horizontal,
		// ��ֱ
		EO_Vertial,
	};

	/**
	*	������������
	*/
	class LayoutSpacerItem : public render::Node, public LayoutItem
	{
	public:
		LayoutSpacerItem();
		virtual ~LayoutSpacerItem();
	public:
		/**
		*	���ÿ������
		*/
		void setOrientation(Orientation eType);
		/**
		*	��ȡ�������
		*/
		Orientation getOrientation();
	protected:
		// �������
		Orientation m_eOrientation;
	};
}