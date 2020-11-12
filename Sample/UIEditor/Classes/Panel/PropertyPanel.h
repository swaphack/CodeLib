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
	};
}