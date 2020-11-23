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
		void loadProperty();
		/**
		*	��������
		*/
		void saveProperty();
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
		// Ŀ��
		ui::LayoutItem* m_pTargetItem = nullptr;
		// ����
		render::CtrlText* m_pTextType = nullptr;
		// ����
		render::CtrlEditText* m_pEditTextName = nullptr;

		// ���
		render::CtrlEditText* m_pEditAnchorPointX = nullptr;
		render::CtrlEditText* m_pEditAnchorPointY = nullptr;
		// ���
		render::CtrlEditText* m_pEditSizeW = nullptr;
		render::CtrlEditText* m_pEditSizeH = nullptr;
		// ����
		render::CtrlEditText* m_pEditScaleX = nullptr;
		render::CtrlEditText* m_pEditScaleY = nullptr;
		// ����
		render::CtrlEditText* m_pEditPosX = nullptr;
		render::CtrlEditText* m_pEditPosY = nullptr;
		// ��ת
		render::CtrlEditText* m_pEditRotateZ = nullptr;

		render::CtrlButton* m_pBtnMarginTop = nullptr;
		render::CtrlButton* m_pBtnMarginRight = nullptr;
		render::CtrlButton* m_pBtnMarginBottom = nullptr;
		render::CtrlButton* m_pBtnMarginLeft = nullptr;

		// �߾�
		render::CtrlEditText* m_pEditTopValue = nullptr;
		render::CtrlEditText* m_pEditRightValue = nullptr;
		render::CtrlEditText* m_pEditBottomValue = nullptr;
		render::CtrlEditText* m_pEditLeftValue = nullptr;

		render::CtrlEditText* m_pEditWidthValue = nullptr;
		render::CtrlEditText* m_pEditHeightValue = nullptr;
	};
}