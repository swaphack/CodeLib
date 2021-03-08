#pragma once

#include "ui.h"
#include "UIPropertyNode.h"

namespace ue
{

	class UIPropertyWidget : public UIPropertyNode
	{
	public:
// ѡ��ͼƬ
#define ADD_SELECT_IMAGE_FUNC(widget)\
if (widget) {\
	widget->addClickFunc([this](ui::CtrlWidget*) { addSelectImageFile(widget); }); \
} \

	public:
		UIPropertyWidget();
		virtual ~UIPropertyWidget();

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
	public:
		/**
		*	ѡ���ļ�
		*/
		void addSelectImageFile(ui::CtrlButton* btn);
		/**
		*	ѡ���ļ�
		*/
		void addSelectImageFile(ui::CtrlImage* image);
	private:
		ui::CtrlButton* m_pBtnMarginTop = nullptr;
		ui::CtrlButton* m_pBtnMarginRight = nullptr;
		ui::CtrlButton* m_pBtnMarginBottom = nullptr;
		ui::CtrlButton* m_pBtnMarginLeft = nullptr;

		// �߾�
		ui::CtrlEditText* m_pEditTopValue = nullptr;
		ui::CtrlEditText* m_pEditRightValue = nullptr;
		ui::CtrlEditText* m_pEditBottomValue = nullptr;
		ui::CtrlEditText* m_pEditLeftValue = nullptr;

		ui::CtrlEditText* m_pEditWidthValue = nullptr;
		ui::CtrlEditText* m_pEditHeightValue = nullptr;
	};
}