#pragma once


#include "Panel.h"

namespace ue
{
	// 属性栏
	class PropertyPanel : public Panel
	{
	public:
		PropertyPanel();
		virtual ~PropertyPanel();
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
		ui::LayoutItem* m_pTargetItem = nullptr;
		// 类型
		render::CtrlText* m_pTextType = nullptr;
		// 名称
		render::CtrlEditText* m_pEditTextName = nullptr;

		// 描点
		render::CtrlEditText* m_pEditAnchorPointX = nullptr;
		render::CtrlEditText* m_pEditAnchorPointY = nullptr;
		// 面积
		render::CtrlEditText* m_pEditSizeW = nullptr;
		render::CtrlEditText* m_pEditSizeH = nullptr;
		// 缩放
		render::CtrlEditText* m_pEditScaleX = nullptr;
		render::CtrlEditText* m_pEditScaleY = nullptr;
		// 坐标
		render::CtrlEditText* m_pEditPosX = nullptr;
		render::CtrlEditText* m_pEditPosY = nullptr;
	};
}