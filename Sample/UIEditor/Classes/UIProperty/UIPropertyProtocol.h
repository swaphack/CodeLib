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
		*	��ʼ���ؼ�
		*/
		virtual void initPropertyUI(ui::CtrlWidget* root) = 0;
		/**
		*	���ؿؼ�����
		*/
		virtual void readWidgetProperty() = 0;
		/**
		*	����ؼ�����
		*/
		virtual void writeWidgetProperty() = 0;
		/**
		*	����ؼ�����
		*/
		void saveProperty();
		/**
		*	���ÿؼ�
		*/
		void setTarget(ui::CtrlWidget* widget);
	protected:
		ui::CtrlWidget* m_pTarget = nullptr;
	};
}