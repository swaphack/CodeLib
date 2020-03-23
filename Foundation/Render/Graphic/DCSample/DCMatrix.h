#pragma once

#include "macros.h"

namespace render
{
	/**
	*	����
	*/
	class DCMatrix : public DrawCommand
	{
	public:
		bool Push;
	public:
		DCMatrix();
		virtual ~DCMatrix();
	public:
		virtual void draw();
	public:
		static DCMatrix* create(bool push);
	};
}