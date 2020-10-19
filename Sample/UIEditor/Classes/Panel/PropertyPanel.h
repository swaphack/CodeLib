#pragma once


#include "Panel.h"

namespace ue
{
	// ������
	class PropertyPanel : public Panel
	{
	public:
		PropertyPanel();
		virtual ~PropertyPanel();
	public:
		virtual bool init();
	public:
		/**
		*	��������
		*/
		void updateProperty(ui::LayoutItem* item);
	protected:
		/**
		*	��ʼ��
		*/
		virtual void initUI();
		/**
		*	�¼���
		*/
		virtual void initEvent();
		/**
		*	��ʼ���ı�
		*/
		virtual void initText();
	private:
		// ����
		render::CtrlText* m_pTextType = nullptr;
		// ����
		render::CtrlEditText* m_pEditTextName = nullptr;
	};
}