#pragma once

#include "NodeLoader.h"

using namespace render;

namespace ui
{
#define ELEMENT_NAME_IMAGE			"Image"

	class ImageLoader : public NodeLoader
	{
	public:
		ImageLoader();
		virtual ~ImageLoader();
	protected:
		virtual void parseAttributes();

		virtual void saveAttributes();
	public:
		INIT_LOADER_WIDGET(CtrlImage, ELEMENT_NAME_IMAGE);
	};
}