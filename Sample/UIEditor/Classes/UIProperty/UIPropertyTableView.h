#pragma once

#include "UIPropertyScrollView.h"

namespace ue
{
	class UIPropertyTableView : public UIPropertyScrollView
	{
	public:
		UIPropertyTableView();
		virtual ~UIPropertyTableView();

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