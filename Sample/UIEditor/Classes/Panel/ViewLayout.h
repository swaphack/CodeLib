#pragma once

#include "Panel.h"

namespace ue
{
	class DesignPanel;
	class PropertyPanel;

	// 视图布局
	class ViewLayout : public Panel
	{
	public:
		ViewLayout();
		virtual ~ViewLayout();
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
	private:
		// 设计面板
		DesignPanel* m_pDesignPanel = nullptr;
	};
}