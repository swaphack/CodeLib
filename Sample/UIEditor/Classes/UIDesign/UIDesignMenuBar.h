#pragma once

#include "Panel/Panel.h"

namespace ue
{
	// �˵���
	class UIDesignMenuBar : public Panel
	{
	public:
		UIDesignMenuBar();
		virtual ~UIDesignMenuBar();
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
