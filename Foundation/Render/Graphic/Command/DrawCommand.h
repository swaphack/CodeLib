#pragma once

#include "system.h"

namespace render
{
	/**
	*	��������
	*/
	class DrawCommand : public sys::Object
	{
	public:
		DrawCommand();
		virtual ~DrawCommand();
	public:
		/**
		*	����
		*/
		virtual void draw() = 0;
	};
}