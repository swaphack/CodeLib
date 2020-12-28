#pragma once

#include "Panel/Panel.h"

namespace ue
{
	// 菜单栏
	class UIDesignMenuBar : public Panel
	{
	public:
		UIDesignMenuBar();
		virtual ~UIDesignMenuBar();
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
	};
}
