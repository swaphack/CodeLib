#pragma once

#include "macros.h"
#include "UINodeLoader.h"

#include <map>
#include <string>

namespace uieditor
{
	// uiº”‘ÿ
	class UILoader
	{
	public:
		UILoader();
		virtual ~UILoader();
	public:
		render::UINode* load(const char* filename);
	protected:
	private:
		std::map<std::string, UINodeLoader*> _nodeParsers;
	};
}