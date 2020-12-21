#pragma once

#include "LayoutItemEx.h"

namespace ui
{
	// ����
	enum class SpacerOrientation
	{
		// ˮƽ
		Horizontal,
		// ��ֱ
		Vertial,
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