#pragma once

#include "Panel.h"

namespace ue
{
	// �˵���
	class MenuBar : public Panel
	{
	public:
		MenuBar();
		virtual ~MenuBar();
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
