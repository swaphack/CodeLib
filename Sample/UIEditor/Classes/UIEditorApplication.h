#pragma once

#include "render.h"

#include "Config/import.h"

namespace ue
{
	// ui�༭��
	class UIEditorApplication : public render::RenderApplication
	{
	public:
		UIEditorApplication();
		virtual ~UIEditorApplication();
	public:
		virtual void show();
	private:
		IDEConfig _ideConfig;
		ProjectConfig _projectConfig;
	};
}

