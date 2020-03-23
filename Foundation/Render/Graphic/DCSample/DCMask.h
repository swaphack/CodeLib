#pragma once

#include "DCColor.h"

namespace render
{
	/**
	*	узуж
	*/
	class DCMask : public DCColor
	{
	public:
		math::Vector3 Position[4];
	public:
		DCMask();
		virtual ~DCMask();
	public:
		virtual void drawDC();
	public:
		static DCMask* create(const RectVertex* rectVertex, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend);
	};
}