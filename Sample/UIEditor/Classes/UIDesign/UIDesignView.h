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
		*	��ȡȡ��ѡ��
		*/
		ui::CtrlWidget* getSelectedTarget() const;
		/**
		*	��������ļ�
		*/
		void setDesignFile(const std::string& filepath);
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
		*	�����Ļ
		*/
		virtual bool onTouchBegan(float x, float y, bool include);
		/**
		*	����Ļ�ϻ���
		*/
		virtual bool onTouchMoved(float x, float y, bool include);
		/**
		*	�뿪��Ļ
		*/
		virtual bool onTouchEnded(float x, float y, bool include);
	protected:
		/**
		*	�����ǰ������
		*/
		bool touchFrontWidget(ui::CtrlWidget* widget,float x, float y);
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
