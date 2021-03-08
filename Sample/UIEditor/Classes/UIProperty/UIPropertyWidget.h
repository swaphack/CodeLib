#pragma once

#include "ui.h"
#include "UIPropertyNode.h"

namespace ue
{

	class UIPropertyWidget : public UIPropertyNode
	{
	public:
// 选择图片
#define ADD_SELECT_IMAGE_FUNC(widget)\
if (widget) {\
	widget->addClickFunc([this](ui::CtrlWidget*) { addSelectImageFile(widget); }); \
} \

	public:
		UIPropertyWidget();
		virtual ~UIPropertyWidget();

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
	public:
		/**
		*	选择文件
		*/
		void addSelectImageFile(ui::CtrlButton* btn);
		/**
		*	选择文件
		*/
		void addSelectImageFile(ui::CtrlImage* image);
	private:
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