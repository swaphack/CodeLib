#pragma once
#include "Panel/Panel.h"

namespace ue
{
	class UIPropertyProtocol;

	// ������
	class UIDesignProperty : public Panel
	{
	public:
		UIDesignProperty();
		virtual ~UIDesignProperty();
	public:
		virtual bool init();
	public:
		/**
		*	���ؿؼ�
		*/
		void loadWidget(ui::CtrlWidget* pWidget);
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
	private:
		// �����б�
		ui::CtrlListView* m_pListProperty = nullptr;

		// Ŀ��
		ui::CtrlWidget* m_pTargetItem = nullptr;
		UIPropertyProtocol* m_pCurUIProperty = nullptr;
		ui::CtrlWidget* m_pUIFile = nullptr;

		std::map<std::string, UIPropertyProtocol*> m_mapWidgetPropertyProtocol;
	};
}