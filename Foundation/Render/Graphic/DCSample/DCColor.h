#pragma once

#include "macros.h"

namespace render
{
	class DCColor : public DrawCommand
	{
	public:
		// ��ɫ
		sys::Color4F Color;
		// ��ɫ����
		BlendParam Blend;
	public:
		DCColor();
		virtual ~DCColor();
	public:
		virtual void draw();
		void initColor(const sys::Color4B& color, uint8_t opacity, const BlendParam& blend);
	protected:
		virtual void drawDC();
	public:
		static DCColor* create(const sys::Color4B& color, uint8_t opacity, const BlendParam& blend);
	};
}