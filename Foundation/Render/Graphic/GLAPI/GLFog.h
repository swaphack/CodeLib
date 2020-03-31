#pragma once

#include "macros.h"

namespace render
{
	/**
	*	Он
	*/
	class GLFog
	{
	public:
		static void setFogMode(FogMode mode);
		static void setFogDensity(float value);
		static void setFogStart(float value);
		static void setFogEnd(float value);
		static void setFogIndex(float value);
		static void setFogColor(const sys::Color4F& color);
	};
}