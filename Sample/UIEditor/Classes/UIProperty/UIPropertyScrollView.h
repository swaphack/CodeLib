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
		*	初始化控件
		*/
		virtual void initPropertyUI(ui::CtrlWidget* root);
		/**
		*	加载控件属性
		*/
		virtual void readWidgetProperty();
		/**
		*	保存控件属性
		*/
		virtual void writeWidgetProperty();
	private:
		ui::CtrlEditText* m_pScrollDirection = nullptr;
		ui::CtrlButton* m_pHorizontalScroll = nullptr;
		ui::CtrlButton* m_pVerticalScroll = nullptr;
		ui::CtrlEditText* m_pMoveMultiple = nullptr;
	};
}