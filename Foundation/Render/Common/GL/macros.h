#pragma once
#include "../../Resource/import.h"

namespace render
{
	struct BlendParam 
	{
		int src;
		int dest;

		BlendParam()
		{
			src = GL_SRC_ALPHA;
			dest = GL_ONE_MINUS_SRC_ALPHA;
		}
	};
}
