#pragma once

#include "macros.h"

namespace render
{
	/**
	*	ø’º‰ Ù–‘
	*/
	class DCSpace : public DrawCommand
	{
	public:
		bool Relative;
		sys::Vector Position;
		sys::Vector Scale;
		sys::Vector Rotation;
	public:
		DCSpace();
		virtual ~DCSpace();
	public:
		virtual void draw();
	public:
		static DCSpace* create(const sys::Vector& position, const sys::Vector& scale, const sys::Vector& rotation, bool relative);
	};
}