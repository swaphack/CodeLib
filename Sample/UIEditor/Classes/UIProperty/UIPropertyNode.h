#pragma once

#include "ui.h"
#include "UIPropertyProtocol.h"

namespace ue
{
	// �ڵ�
	class UIPropertyNode : public UIPropertyProtocol
	{
		// ѡ��Ͳ�ѡ��״̬
#define ADD_TOGGLE_FUNC(btn, Type, func)\
if (btn) { \
	btn->addClickFunc([this](ui::CtrlWidget*) {\
		if (m_pTarget == nullptr) return; \
		auto pType = m_pTarget->as<Type>(); \
		if (pType == nullptr) return;\
		btn->setSelectState(!btn->isSelected()); \
		pType->func(btn->isSelected());\
	});\
}\

	public:
		UIPropertyNode();
		virtual ~UIPropertyNode();
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
		// ����
		ui::CtrlText* m_pTextType = nullptr;
		// ����
		ui::CtrlEditText* m_pEditName = nullptr;
		// ��ǩ
		ui::CtrlEditText* m_pEditTag = nullptr;

		// ����
		ui::CtrlButton* m_pVisibleState = nullptr;

		// ���
		ui::CtrlEditText* m_pEditAnchorPointX = nullptr;
		ui::CtrlEditText* m_pEditAnchorPointY = nullptr;
		// ���
		ui::CtrlEditText* m_pEditSizeW = nullptr;
		ui::CtrlEditText* m_pEditSizeH = nullptr;
		// ����
		ui::CtrlEditText* m_pEditScaleX = nullptr;
		ui::CtrlEditText* m_pEditScaleY = nullptr;
		// ����
		ui::CtrlEditText* m_pEditPosX = nullptr;
		ui::CtrlEditText* m_pEditPosY = nullptr;
		// ��ת
		ui::CtrlEditText* m_pEditRotateZ = nullptr;
	};
}