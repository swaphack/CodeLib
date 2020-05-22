#pragma once

#include "system.h"

namespace ui
{
	// ��С��������
	enum class SizeType
	{
		// �̶�
		FIXED,
		// ��С����Сʱ������С
		MINIMUM,
		// �Ŵ����ʱ�������
		MAXIMUM,
		// �Զ�����
		EXPANDING,
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

		SizePolicy() :width(SizeType::EXPANDING), height(SizeType::EXPANDING){}
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
	enum class ElementType
	{
		/**
		*	δ����
		*/
		NONE,
		/**
		*	�ؼ�
		*/
		WIDGET,
		/**
		*	����
		*/
		LAYOUT,
	};

	/**
	*	���ַ���
	*/
	enum class LayoutDirection
	{
		// ��
		NONE,
		// ��ֱ����
		HORIZONTAL,
		// ˮƽ����
		ERTICAL,
	};

	/**
	* λ��
	*/
	enum class AnchorPosition
	{
		// �ޣ�Ĭ��
		NONE,
		DOWN_LEFT,
		DOWN_CENTER,
		DOWN_RIGHT,
		CENTER_LEFT,
		CENTER_CENTER,
		CENTER_RIGHT,
		UP_LEFT,
		UP_CENTER,
		UP_RIGHT,
	};
}