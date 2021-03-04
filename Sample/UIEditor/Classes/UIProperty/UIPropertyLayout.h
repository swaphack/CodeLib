#pragma once

#include "UIPropertyWidget.h"

namespace ue
{
	class UIPropertyLayout : public UIPropertyWidget
	{
	public:
		UIPropertyLayout();
		virtual ~UIPropertyLayout();

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
		ui::CtrlButton* m_pShowImage = nullptr;
		ui::CtrlButton* m_pShowMask = nullptr;
		ui::CtrlEditText* m_pImagePath = nullptr;
	};
}