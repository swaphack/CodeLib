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
		ui::CtrlButton* m_pHorizontalScroll = nullptr;
		ui::CtrlButton* m_pVerticalScroll = nullptr;
		ui::CtrlEditText* m_pMoveMultiple = nullptr;
	};
}