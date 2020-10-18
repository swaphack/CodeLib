#pragma once

#include "Panel.h"

namespace ue
{
	// �����
	class DesignPanel : public Panel
	{
	public:
		DesignPanel();
		virtual ~DesignPanel();
	public:
		virtual bool init();
	public:
		/**
		*	�����ļ�
		*/
		void setUIFile(const std::string& filepath);
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
	protected:
		//�����ļ�
		ui::CtrlFile* m_pUIFile = nullptr;
	};
}
