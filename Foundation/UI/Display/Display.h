#pragma once

#include "macros.h"
#include "ui_common.h"

namespace ui
{
	class Layout;
	/**
	*	界面显示
	*/
	class Display : public sys::Object
	{
	public:
		Display();
		virtual ~Display();
	public:
		/**
		*	设置ui根节点
		*/
		void setUIRoot(render::Node* root);
		/**
		*	显示
		*/
		void show();
		/**
		*	隐藏
		*/
		void hide();
		/**
		*	销毁
		*/
		void close();
		/**
		*	重新加载
		*/
		void reload();
		/**
		*	设置文件路径
		*/
		void setFilePath(const std::string& filepath);
		/**
		*	文件路径
		*/
		const std::string& getFilePath();
		/**
		*	窗口界面大小
		*/
		const math::Size& getViewSize();
		/**
		*	获取布局方向
		*/
		LayoutDirection getLayoutDirection();
		/**
		*	获取布局
		*/
		Layout* getLayout();
	protected:
		/**
		*	当窗口大小发生改变时
		*/
		void onViewSizeChanged(const math::Size& inputSize);
		/**
		*	加载界面文件
		*/
		bool loadFile();
		/**
		*	初始化
		*/
		void initUI();
		/**
		*	事件绑定
		*/
		virtual void initEvent();
		/**
		*	初始化文本
		*/
		virtual void initText();
		/**
		*	大小自动设置
		*/
		void autoResize();
	protected:
		// 文件路径
		std::string m_strFilePath;
		// ui根节点
		render::Node* m_pRoot;
		// 布局
		Layout* m_pLayout;
		// 布局方向
		LayoutDirection m_eLayoutDirection;
		// 窗口界面大小
		math::Size m_sViewSize;
	};
}