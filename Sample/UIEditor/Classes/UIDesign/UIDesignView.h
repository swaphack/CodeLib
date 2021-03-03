#pragma once

#include "Panel/Panel.h"

namespace ue
{
	// �����
	class UIDesignView : public Panel
	{
	public:
		UIDesignView();
		virtual ~UIDesignView();
	public:
		virtual bool init();
	public:
		/**
		*	ȡ��ѡ��
		*/
		void unselectTarget();
		/**
		*	����ѡ����
		*/
		void setSelectTarget(ui::CtrlWidget* target);
		/**
		*	��ȡȡ��ѡ��
		*/
		ui::CtrlWidget* getSelectedTarget() const;
		/**
		*	��������ļ�
		*/
		void setDesignFile(const std::string& filepath);
		/**
		*	��ȡui����ļ����ڵ�
		*/
		ui::CtrlWidget* getUIRoot() const;
		/**
		*	���沢���¼��ؽ���
		*/
		void saveAndReload();
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
		/**
		*	ѡ��
		*/
		void selectTarget(ui::CtrlWidget* target);
	protected:
		void saveFile();
		void reloadFile();
	protected:
		// ����ļ�
		ui::CtrlWidget* m_pUIFile = nullptr;
		// �Ƿ�ѡ��
		bool m_bSelected = false;
		// ѡ�ж���
		ui::CtrlWidget* m_pSelectedTarget = nullptr;

		ui::CtrlWidget* m_pViewScene = nullptr;

		std::string m_strFileName;
	};
}
