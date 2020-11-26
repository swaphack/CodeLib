#pragma once

#include "Panel.h"

namespace ue
{
	// 设计栏
	class DesignPanel : public Panel
	{
	public:
		DesignPanel();
		virtual ~DesignPanel();
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
		ui::LayoutItem* getSelectedTarget() const;
		/**
		*	设置涉及文件
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
		bool touchFrontWidget(ui::LayoutItem* layoutItem,float x, float y);
	protected:
		// 设计文件
		ui::LayoutItem* m_pUIFile = nullptr;
		// 是否选中
		bool m_bSelected = false;
		// 选中对象
		ui::LayoutItem* m_pSelectedTarget = nullptr;

		ui::Layout* m_pViewScene = nullptr;
	};
}
