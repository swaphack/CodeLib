#pragma once

#include "UIPropertyWidget.h"

namespace ue
{
	class UIPropertyScrollView : public UIPropertyWidget
	{
	public:
		UIPropertyScrollView();
		virtual ~UIPropertyScrollView();

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
		ui::CtrlButton* m_pHorizontalScroll = nullptr;
		ui::CtrlButton* m_pVerticalScroll = nullptr;
		ui::CtrlEditText* m_pMoveMultiple = nullptr;
	};
}