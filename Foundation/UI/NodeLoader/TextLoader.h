#pragma once

#include "NodeLoader.h"

using namespace render;

namespace ui
{
	class TextLoader : public NodeLoader
	{
	public:
		TextLoader();
		virtual ~TextLoader();
	protected:
		virtual void parseAttribute();

		virtual void saveAttributes();
	private:
		INIT_LOADER_NODE(UIText);
	};
}