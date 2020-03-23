#pragma once

#include "DCColor.h"

#include <vector>

namespace render
{
	/**
	*	»æÖÆ
	*/
	class DCDraw : public DCColor
	{
	public:
		std::vector<math::Vector3> Points;
		float Width;
		int Type;
	public:
		DCDraw();
		virtual ~DCDraw();
	public:
		virtual void drawDC();
	public:
		static DCDraw* create(int type, const std::vector<math::Vector3>& points, float width, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend);
	};
}