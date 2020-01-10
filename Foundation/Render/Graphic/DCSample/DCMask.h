#pragma once

#include "macros.h"

namespace render
{
	/**
	*	����
	*/
	class DCMask : public DrawCommand
	{
	public:
		sys::Color4F Color;
		BlendParam Blend;
		math::Vector3 Position[4];
	public:
		DCMask();
		virtual ~DCMask();
	public:
		virtual void draw();
	public:
		static DCMask* create(const RectVertex* rectVertex, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend);
	};
}