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