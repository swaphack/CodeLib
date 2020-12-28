#pragma once

#include "Panel/Panel.h"

namespace ue
{
	// 控件栏
	class UIDesignWidget : public Panel
	{
	public:
		UIDesignWidget();
		virtual ~UIDesignWidget();
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
	public:
	};
}
