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
	class SizePolicy : public sys::Object
	{
	public:
		SizePolicy();
		virtual ~SizePolicy();
	public:
		/**
		*	 ���ÿ�ȵ�������
		*/
		void setWidthType(SizeType type);
		/**
		*	 ��ȡ��ȵ�������
		*/
		SizeType getWidthType();
		/**
		*	 ���ø߶ȵ�������
		*/
		void setHeightType(SizeType type);
		/**
		*	 ��ȡ�߶ȵ�������
		*/
		SizeType getHeightType();
	protected:
		// ��ȵ�������
		SizeType m_stWidth;
		// �߶ȵ�������
		SizeType m_stHeight;
	};
}