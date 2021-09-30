#pragma once

#include "render.h"
#include "ui.h"
#include "Config/WidgetConfig.h"

namespace ue
{
	class UIDesignWindow;

	// 主窗体
	class MainWindow : public render::Scene
	{
	public:
		MainWindow();
		virtual ~MainWindow();
	public:
		virtual bool init();
	public:
		/**
		*	加载界面配置文件
		*/
		void setUIFile(const std::string& config);
		/**
		*	加载控件配置文件
		*/
		void setWidgetFile(const std::string& config);
	protected:
		/**
		*	创建控件
		*/
		ui::CtrlWidget* createWidget(const std::string& widgetName);
		/**
		*	创建控件属性
		*/
		ui::CtrlWidget* createWidgetProperty(const std::string& widgetName);
	protected:
		void updateCamera();
		void addFPS();
	private:
		UIDesignWindow* _viewLayout = nullptr;

		WidgetConfig _widgetConfig;
	};
}

