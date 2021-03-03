#pragma once

#include "UIPropertyWidget.h"

namespace ue
{
	class UIPropertyButton : public UIPropertyWidget
	{
	public:
		UIPropertyButton();
		virtual ~UIPropertyButton();

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

		ui::CtrlButton* m_pNormalImagePath = nullptr;
		ui::CtrlButton* m_pSelectedImagePath = nullptr;
		ui::CtrlButton* m_pDisabledImagePath = nullptr;
	};
}