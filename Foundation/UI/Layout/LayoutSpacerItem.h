#pragma once

#include "LayoutItemEx.h"

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
	class LayoutSpacerItem : public LayoutItemEx
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