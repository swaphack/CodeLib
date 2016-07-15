#pragma once

#include "NodeLoader.h"

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
		INIT_LOADER_NODE(UIImage);
	};
}