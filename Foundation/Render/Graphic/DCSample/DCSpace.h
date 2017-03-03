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
		sys::Vector3 Position;
		sys::Vector3 Scale;
		sys::Vector3 Rotation;
	public:
		DCSpace();
		virtual ~DCSpace();
	public:
		virtual void draw();
	public:
		static DCSpace* create(const sys::Vector3& position, const sys::Vector3& scale, const sys::Vector3& rotation, bool relative);
	};
}