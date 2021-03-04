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

		ui::CtrlEditText* m_pFontText = nullptr;
		ui::CtrlEditText* m_pFontPath = nullptr;
		ui::CtrlEditText* m_pFontSize = nullptr;
		ui::CtrlEditText* m_pFontHorizontalType = nullptr;
		ui::CtrlEditText* m_pFontVerticalType = nullptr;
	};
}