#pragma once

#include "DCColor.h"

namespace render
{
	class ModelDetail;
	/**
	*	Ä£ÐÍ
	*/
	class DCModel : public DCColor
	{
	public:
		ModelDetail* Detail;
	public:
		DCModel();
		virtual ~DCModel();
	public:
		virtual void drawDC();
	public:
		static DCModel* create(ModelDetail* detail, const sys::Color4B& color, uint8_t opacity, const BlendParam& blend);
	};
}