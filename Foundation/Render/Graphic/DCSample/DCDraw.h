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
		std::vector<math::Vector3> Points;
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
		static DCDraw* create(int type, const std::vector<math::Vector3>& points, float width, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend);
	};
}