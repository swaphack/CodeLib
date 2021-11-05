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