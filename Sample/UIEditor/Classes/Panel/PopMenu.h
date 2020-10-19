#pragma once

#include "Panel.h"

namespace ue
{
	/**
	*	弹出菜单
	*/
	class PopMenu : public Panel
	{
	public:
		PopMenu();
		virtual ~PopMenu();
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
		/**
		*	显示
		*/
		static void show();
		/**
		*	隐藏
		*/
		static void hide();
		/**
		*	是否显示
		*/
		static bool isShow();
		/**
		*	实例
		*/
		static PopMenu* getInstance();
	private:
		// 弹窗
		static PopMenu* sPopMenu;
	};
}
