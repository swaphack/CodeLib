#pragma once

#include "Panel/Panel.h"

namespace ue
{
	// �ؼ���
	class UIDesignWidget : public Panel
	{
	public:
		UIDesignWidget();
		virtual ~UIDesignWidget();
	public:
		virtual bool init();
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
	public:
	};
}
