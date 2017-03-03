#pragma once

#include "macros.h"

#include <vector>

namespace render
{
	/**
	*	»æÖÆ
	*/
	class DCDraw : public DrawCommand
	{
	public:
		std::vector<sys::Vector3> Points;
		sys::Color4F Color;
		float Width;
		int Type;
		BlendParam Blend;
	public:
		DCDraw();
		virtual ~DCDraw();
	public:
		virtual void draw();
	public:
		static DCDraw* create(int type, const std::vector<sys::Vector3>& points, float width, const sys::Color4B& color, uchar opacity, const BlendParam& blend);
	};
}