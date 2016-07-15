#pragma once

namespace sys
{
	struct Size
	{
		float width;
		float height;

		Size() :width(0), height(0){}
		Size(float w, float h) :width(w), height(h){}

	public:
		static Size One;
	};

	__declspec(selectany) Size Size::One = Size(1,1);
}