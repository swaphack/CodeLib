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
		*	更新属性
		*/
		void updateProperty(ui::LayoutItem* item);
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
		// 类型
		render::CtrlText* m_pTextType = nullptr;
		// 名称
		render::CtrlEditText* m_pEditTextName = nullptr;
	};
}