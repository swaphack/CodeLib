#pragma once

#include "UIPropertyListView.h"

namespace ue
{
	class UIPropertyGridView : public UIPropertyListView
	{
	public:
		UIPropertyGridView();
		virtual ~UIPropertyGridView();

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