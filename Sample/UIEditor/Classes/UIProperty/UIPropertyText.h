#pragma once

#include "UIPropertyWidget.h"

namespace ue
{
	class UIPropertyText : public UIPropertyWidget
	{
	public:
		UIPropertyText();
		virtual ~UIPropertyText();

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

		ui::CtrlEditText* m_pFontText = nullptr;
		ui::CtrlEditText* m_pFontPath = nullptr;
		ui::CtrlEditText* m_pFontSize = nullptr;
		ui::CtrlEditText* m_pFontHorizontalType = nullptr;
		ui::CtrlEditText* m_pFontVerticalType = nullptr;
	};
}