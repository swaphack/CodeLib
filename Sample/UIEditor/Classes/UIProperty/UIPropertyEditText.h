#pragma once

#include "UIPropertyWidget.h"

namespace ue
{
	class UIPropertyEditText : public UIPropertyWidget
	{
	public:
		UIPropertyEditText();
		virtual ~UIPropertyEditText();

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