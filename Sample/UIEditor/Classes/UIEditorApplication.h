#pragma once

#include "render.h"

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
	protected:
	};
}

