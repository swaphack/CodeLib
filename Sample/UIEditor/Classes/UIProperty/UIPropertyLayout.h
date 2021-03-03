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
		*	��ʼ���ؼ�
		*/
		virtual void initPropertyUI(ui::CtrlWidget* root);
		/**
		*	���ؿؼ�����
		*/
		virtual void readWidgetProperty();
		/**
		*	����ؼ�����
		*/
		virtual void writeWidgetProperty();
	private:
	};
}