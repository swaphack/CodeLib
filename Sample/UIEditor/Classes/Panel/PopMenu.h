#pragma once

#include "SinglePanel.h"

namespace ue
{
	/**
	*	弹出菜单
	*/
	class PopMenu : public SinglePanel
	{
	public:
		PopMenu();
		virtual ~PopMenu();
	public:
		/**
		*	文件路径
		*/
		virtual const char* getPanelPath();
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
