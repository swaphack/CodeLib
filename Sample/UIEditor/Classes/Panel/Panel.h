#pragma once

#include "ui.h"

namespace ue
{
	// 面板
	class Panel : public ui::CtrlFile
	{
	public:
		Panel();
		virtual ~Panel();
	public:
		virtual bool init();
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
	};
}
