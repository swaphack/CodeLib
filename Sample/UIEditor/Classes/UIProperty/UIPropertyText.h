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
	};
}