#pragma once

#include "NodeLoader.h"

using namespace render;

namespace ui
{
#define ELEMENT_NAME_TEXT			"Text"

	class TextLoader : public NodeLoader
	{
	public:
		TextLoader();
		virtual ~TextLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(CtrlText, ELEMENT_NAME_TEXT);
	};
}