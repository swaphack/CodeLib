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
		ui::CtrlButton* m_pFilepath = nullptr;
		ui::CtrlButton* m_pReverseX = nullptr;
		ui::CtrlButton* m_pReverseY = nullptr;
	};
}