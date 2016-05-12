#pragma once

namespace sys
{
	struct Size
	{
		float width;
		float height;

		Size() :width(0), height(0){}
		Size(float w, float h) :width(w), height(h){}
	};
}