#pragma once

#include "Panel/Panel.h"

namespace ue
{
	// 设计栏
	class UIDesignView : public Panel
	{
	public:
		UIDesignView();
		virtual ~UIDesignView();
	public:
		virtual bool init();
	public:
		/**
		*	取消选中
		*/
		void unselectTarget();
		/**
		*	设置选中项
		*/
		void setSelectTarget(ui::CtrlWidget* target);
		/**
		*	获取取消选中
		*/
		ui::CtrlWidget* getSelectedTarget() const;
		/**
		*	设置设计文件
		*/
		void setDesignFile(const std::string& filepath);
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
	protected:
		/**
		*	点击最前面的组件
		*/
		bool touchFrontWidget(ui::CtrlWidget* widget, const math::Vector2& touchPoint);
		/**
		*	选中
		*/
		void selectTarget(ui::CtrlWidget* target);
	protected:
		void saveFile();
		void reloadFile();
	protected:
		// 设计文件
		ui::CtrlWidget* m_pUIFile = nullptr;
		// 是否选中
		bool m_bSelected = false;
		// 选中对象
		ui::CtrlWidget* m_pSelectedTarget = nullptr;

		ui::CtrlWidget* m_pViewScene = nullptr;

		std::string m_strFileName;
	};
}
