#pragma once

#include "macros.h"

namespace render
{
	/**
	*	узуж
	*/
	class DCMask : public DrawCommand
	{
	public:
		sys::Color4F Color;
		BlendParam Blend;
		sys::Vector3 Position[4];
	public:
		DCMask();
		virtual ~DCMask();
	public:
		virtual void draw();
	public:
		static DCMask* create(const RectangeVertex* rectVertex, const sys::Color4B& color, uchar opacity, const BlendParam& blend);
	};
}