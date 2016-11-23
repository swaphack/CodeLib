#pragma once

#include "macros.h"

namespace render
{
	/**
	*	»æÖÆÃüÁî
	*/
	class DrawCommand : public sys::Object
	{
	public:
		DrawCommand();
		virtual ~DrawCommand();
	public:
		/**
		*	»æÖÆ
		*/
		virtual void draw() = 0;
	};
}