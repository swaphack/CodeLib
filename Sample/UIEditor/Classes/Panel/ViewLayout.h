#pragma once

#include "Panel.h"

namespace ue
{
	// ��ͼ����
	class ViewLayout : public Panel
	{
	public:
		ViewLayout();
		virtual ~ViewLayout();
	protected:
		/**
		*	��ʼ��
		*/
		virtual void initUI();
		/**
		*	�¼���
		*/
		virtual void initEvent();
		/**
		*	��ʼ���ı�
		*/
		virtual void initText();
	};
}