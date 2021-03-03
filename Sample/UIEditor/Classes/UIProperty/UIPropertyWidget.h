#pragma once

#include "ui.h"
#include "UIPropertyProtocol.h"

namespace ue
{
	class UIPropertyWidget : public UIPropertyProtocol
	{
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
	private:
		// ����
		ui::CtrlText* m_pTextType = nullptr;
		// ����
		ui::CtrlEditText* m_pEditTextName = nullptr;

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