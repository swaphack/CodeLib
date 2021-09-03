#pragma once

#include "system.h"
#include "render.h"
#include "Layout/macros.h"
#include "UI/CtrlWidget.h"

namespace ui
{
	class Layout;
	/**
	*	界面显示
	*/
	class CtrlFile : 
		public CtrlWidget, 
		public render::WindowProtocol
	{
	public:
		CtrlFile();
		virtual ~CtrlFile();
	public:
		virtual bool init();
	public:
		/**
		*	显示
		*/
		void show();
	public:
		/**
		*	设置文件路径
		*/
		void setFilePath(const std::string& filepath);
		/**
		*	文件路径
		*/
		const std::string& getFilePath();
		/**
		*	重新加载
		*/
		void reload();
		/**
		*	保存
		*/
		void save();
		/**
		*	保存为指定目录文件
		*/
		void saveTo(const std::string& filepath);
	public:
		/**
		*	窗口界面大小
		*/
		const math::Size& getViewSize() const;
		/**
		*	获取布局方向
		*/
		LayoutDirection getLayoutDirection() const;
	public:
		/**
		*	是否是根视图
		*/
		void setRootView(bool root);
		/**
		*	是否是根视图
		*/
		bool isRootView() const;
		/**
		*	大小自动设置
		*/
		void autoResize();
	protected:
		/**
		*	当窗口大小发生改变时
		*/
		virtual void onWindowSizeChange(const math::Size& inputSize);
		/**
		*	加载界面文件
		*/
		bool loadFile();
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
		// 文件路径
		std::string m_strFilePath;
		// 布局方向
		LayoutDirection m_eLayoutDirection = LayoutDirection::NONE;
		// 窗口界面大小
		math::Size m_sViewSize;
		// 是否根视图
		bool m_bRootView = false;
		// 根节点
		ui::CtrlWidget* m_pRootWidget = nullptr;
	};
}