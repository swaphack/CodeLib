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
		*	点击屏幕
		*/
		virtual bool onTouchBegan(float x, float y, bool include);
		/**
		*	在屏幕上滑动
		*/
		virtual bool onTouchMoved(float x, float y, bool include);
		/**
		*	离开屏幕
		*/
		virtual bool onTouchEnded(float x, float y, bool include);
	protected:
		/**
		*	点击最前面的组件
		*/
		bool touchFrontWidget(ui::CtrlWidget* widget,float x, float y);
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
