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