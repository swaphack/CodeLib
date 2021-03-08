#pragma once

#include "ui.h"
#include "UIPropertyProtocol.h"

namespace ue
{
	// 节点
	class UIPropertyNode : public UIPropertyProtocol
	{
		// 选择和不选中状态
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
		*	初始化控件
		*/
		virtual void initPropertyUI(ui::CtrlWidget* root);
		/**
		*	加载控件属性
		*/
		virtual void readWidgetProperty();
		/**
		*	保存控件属性
		*/
		virtual void writeWidgetProperty();
	private:
		// 类型
		ui::CtrlText* m_pTextType = nullptr;
		// 名称
		ui::CtrlEditText* m_pEditName = nullptr;
		// 标签
		ui::CtrlEditText* m_pEditTag = nullptr;

		// 名称
		ui::CtrlButton* m_pVisibleState = nullptr;

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
	};
}