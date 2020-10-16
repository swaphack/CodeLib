#pragma once

#include "Panel.h"

namespace ue
{
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
	};
}