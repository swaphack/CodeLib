#pragma once

#include "UIPropertyLayout.h"

namespace ue
{
	class UIPropertyScrollView : public UIPropertyLayout
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
		ui::CtrlEditText* m_pScrollDirection = nullptr;
		ui::CtrlButton* m_pHorizontalScroll = nullptr;
		ui::CtrlButton* m_pVerticalScroll = nullptr;
		ui::CtrlEditText* m_pMoveMultiple = nullptr;
	};
}