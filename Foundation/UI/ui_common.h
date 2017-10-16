#pragma once

#include "system.h"

namespace ui
{
	// ��С��������
	enum SizeType
	{
		// �̶�
		EST_Fixed,
		// ��С����Сʱ������С
		EST_Minimum,
		// �Ŵ����ʱ�������
		EST_Maximum,
		// �Զ�����
		EST_Expanding,
	};

	/**
	*	 �����С��������
	*/
	struct SizePolicy 
	{
		// ��ȵ�������
		SizeType width;
		// �߶ȵ�������
		SizeType height;

		SizePolicy() :width(EST_Expanding), height(EST_Expanding){}
		SizePolicy(SizeType w, SizeType h) :width(w), height(h){}

		SizePolicy& operator=(const SizePolicy& value)
		{
			width = value.width;
			height = value.height;

			return *this;
		}
	};

	/**
	*	Ԫ������
	*/
	enum ElementType
	{
		/**
		*	δ����
		*/
		EET_NONE,
		/**
		*	�ؼ�
		*/
		EET_WIDGET,
		/**
		*	����
		*/
		EET_LAYOUT,
	};

	/**
	*	���ַ���
	*/
	enum LayoutDirection
	{
		// ��
		ELD_NONE,
		// ��ֱ����
		ELD_HORIZONTAL,
		// ˮƽ����
		ELD_VERTICAL,
	};

	/**
	* λ��
	*/
	enum AnchorPosition
	{
		// �ޣ�Ĭ��
		EAP_NONE,
		EAP_DOWN_LEFT,
		EAP_DOWN_CENTER,
		EAP_DOWN_RIGHT,
		EAP_CENTER_LEFT,
		EAP_CENTER_CENTER,
		EAP_CENTER_RIGHT,
		EAP_UP_LEFT,
		EAP_UP_CENTER,
		EAP_UP_RIGHT,
	};
}