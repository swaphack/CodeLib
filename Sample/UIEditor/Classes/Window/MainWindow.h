#pragma once

#include "render.h"
#include "ui.h"
#include "Config/WidgetConfig.h"

namespace ue
{
	class UIDesignWindow;

	// ������
	class MainWindow : public render::Scene
	{
	public:
		MainWindow();
		virtual ~MainWindow();
	public:
		virtual bool init();
	public:
		/**
		*	���ؽ��������ļ�
		*/
		void setUIFile(const std::string& config);
		/**
		*	���ؿؼ������ļ�
		*/
		void setWidgetFile(const std::string& config);
	protected:
		/**
		*	�����ؼ�
		*/
		ui::CtrlWidget* createWidget(const std::string& widgetName);
		/**
		*	�����ؼ�����
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

