#pragma once

#include "Panel.h"

namespace ue
{
	// �ؼ���
	class ControlPanel : public Panel
	{
	public:
		ControlPanel();
		virtual ~ControlPanel();
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
