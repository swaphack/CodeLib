#pragma once

#include <string>

namespace ui
{
	class CtrlWidget;
}

namespace ue
{
	class UIPropertyProtocol
	{
	public:
		virtual ~UIPropertyProtocol() {}
	public:
		/**
		*	初始化控件
		*/
		virtual void initPropertyUI(ui::CtrlWidget* root) = 0;
		/**
		*	加载控件属性
		*/
		virtual void readWidgetProperty() = 0;
		/**
		*	保存控件属性
		*/
		virtual void writeWidgetProperty() = 0;
		/**
		*	保存控件属性
		*/
		void saveProperty();
		/**
		*	设置控件
		*/
		void setTarget(ui::CtrlWidget* widget);
	protected:
		ui::CtrlWidget* m_pTarget = nullptr;
	};
}