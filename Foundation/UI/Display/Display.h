#pragma once

#include "macros.h"

namespace ui
{
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
		void dispose();
		/**
		*	重新加载
		*/
		void reload();
		/**
		*	设置文件路径
		*/
		void setFilePath(const char* filepath);
		/**
		*	文件路径
		*/
		const char* getFilePath();
		/**
		*	设置窗口界面大小
		*/
		void setViewSize(const sys::Size& inputSize);
		/**
		*	窗口界面大小
		*/
		const sys::Size& getViewSize();
		/**
		*	当窗口大小发生改变时
		*/
		void onViewSizeChanged(const sys::Size& inputSize);
	protected:
		/**
		*	加载界面文件
		*/
		bool loadFile();
		/**
		*	初始化
		*/
		bool initUI();
		/**
		*	事件绑定
		*/
		virtual bool initEvent();
		/**
		*	初始化文本
		*/
		virtual bool initText();
		/**
		*	获取元件根节点
		*/
		Widget* getWidget();
	protected:
		// 文件路径
		std::string m_strFilePath;
		// 布局
		LayoutItem* m_pLayoutItem;
		// 窗口界面大小
		sys::Size m_sViewSize;
	};
}