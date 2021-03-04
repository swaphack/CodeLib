#pragma once

#include "UIPropertyScrollView.h"

namespace ue
{
	class UIPropertyListView : public UIPropertyScrollView
	{
	public:
		UIPropertyListView();
		virtual ~UIPropertyListView();

	public:
		/**
		*	��ʼ���ؼ�
		*/
		virtual void initPropertyUI(ui::CtrlWidget* root);
		/**
		*	���ؿؼ�����
		*/
		virtual void readWidgetProperty();
		/**
		*	����ؼ�����
		*/
		virtual void writeWidgetProperty();
	private:
		ui::CtrlEditText* m_pScrollDirection = nullptr;
		ui::CtrlEditText* m_pWidthValue = nullptr;
		ui::CtrlEditText* m_pHeightValue = nullptr;
		ui::CtrlButton* m_pUseItemSize = nullptr;
		ui::CtrlButton* m_pShowInCenter = nullptr;
	};
}