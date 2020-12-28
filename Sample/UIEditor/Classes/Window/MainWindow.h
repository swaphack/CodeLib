#pragma once

#include "render.h"

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
	private:
		UIDesignWindow* _viewLayout = nullptr;
	};
}

