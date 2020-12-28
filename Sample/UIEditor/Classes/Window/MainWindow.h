#pragma once

#include "render.h"

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
	private:
		UIDesignWindow* _viewLayout = nullptr;
	};
}

