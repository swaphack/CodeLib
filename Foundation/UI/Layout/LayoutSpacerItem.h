#pragma once

#include "macros.h"

#include "LayoutWidgetItem.h"

namespace ui
{
	// ����
	enum SpacerOrientation
	{
		// ˮƽ
		ESO_Horizontal,
		// ��ֱ
		ESO_Vertial,
	};

	/**
	*	������������
	*/
	class LayoutSpacerItem : public LayoutItem
	{
	public:
		LayoutSpacerItem();
		virtual ~LayoutSpacerItem();
	public:
		/**
		*	���ÿ������
		*/
		void setOrientation(SpacerOrientation eType);
		/**
		*	��ȡ�������
		*/
		SpacerOrientation getOrientation();
	protected:
		// �������
		SpacerOrientation m_eOrientation;
	};
}