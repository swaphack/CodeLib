#pragma once

#include "render.h"

#include "Config/import.h"

namespace ue
{
	// ui编辑器
	class UIEditorApplication : public render::RenderApplication
	{
	public:
		UIEditorApplication();
		virtual ~UIEditorApplication();
	public:
		virtual void show();
	private:
		// 开发环境配置
		IDEConfig _ideConfig;
		// 工程配置
		ProjectConfig _projectConfig;
	};
}

