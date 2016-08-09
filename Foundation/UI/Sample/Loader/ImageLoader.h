#pragma once

#include "NodeLoader.h"

using namespace render;

namespace ui
{
	class ImageLoader : public NodeLoader
	{
	public:
		ImageLoader();
		virtual ~ImageLoader();
	protected:
		virtual void parseAttribute();

		virtual void saveAttributes();
	private:
		INIT_LOADER_NODE(CtrlImage);
	};
}