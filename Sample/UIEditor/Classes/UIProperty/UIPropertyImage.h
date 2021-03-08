#pragma once

#include "UIPropertyWidget.h"

namespace ue
{
	class UIPropertyImage : public UIPropertyWidget
	{
	public:
		UIPropertyImage();
		virtual ~UIPropertyImage();
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
		ui::CtrlButton* m_pFilepath = nullptr;
		ui::CtrlButton* m_pReverseX = nullptr;
		ui::CtrlButton* m_pReverseY = nullptr;
	};
}