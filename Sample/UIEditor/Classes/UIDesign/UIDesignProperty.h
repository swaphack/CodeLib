#pragma once


#include "Panel/Panel.h"

namespace ue
{
	// 属性栏
	class UIDesignProperty : public Panel
	{
	public:
		UIDesignProperty();
		virtual ~UIDesignProperty();
	public:
		virtual bool init();
	public:
		/**
		*	加载属性
		*/
		void loadProperty();
		/**
		*	保存属性
		*/
		void saveProperty();
	protected:
		/**
		*	初始化
		*/
		virtual void initUI();
		/**
		*	事件绑定
		*/
		virtual void initEvent();
		/**
		*	初始化文本
		*/
		virtual void initText();
	private:
		// 目标
		render::Node* m_pTargetItem = nullptr;
		// 类型
		ui::CtrlText* m_pTextType = nullptr;
		// 名称
		ui::CtrlEditText* m_pEditTextName = nullptr;

		// 描点
		ui::CtrlEditText* m_pEditAnchorPointX = nullptr;
		ui::CtrlEditText* m_pEditAnchorPointY = nullptr;
		// 面积
		ui::CtrlEditText* m_pEditSizeW = nullptr;
		ui::CtrlEditText* m_pEditSizeH = nullptr;
		// 缩放
		ui::CtrlEditText* m_pEditScaleX = nullptr;
		ui::CtrlEditText* m_pEditScaleY = nullptr;
		// 坐标
		ui::CtrlEditText* m_pEditPosX = nullptr;
		ui::CtrlEditText* m_pEditPosY = nullptr;
		// 旋转
		ui::CtrlEditText* m_pEditRotateZ = nullptr;

		ui::CtrlButton* m_pBtnMarginTop = nullptr;
		ui::CtrlButton* m_pBtnMarginRight = nullptr;
		ui::CtrlButton* m_pBtnMarginBottom = nullptr;
		ui::CtrlButton* m_pBtnMarginLeft = nullptr;

		// 边距
		ui::CtrlEditText* m_pEditTopValue = nullptr;
		ui::CtrlEditText* m_pEditRightValue = nullptr;
		ui::CtrlEditText* m_pEditBottomValue = nullptr;
		ui::CtrlEditText* m_pEditLeftValue = nullptr;

		ui::CtrlEditText* m_pEditWidthValue = nullptr;
		ui::CtrlEditText* m_pEditHeightValue = nullptr;
	};
}