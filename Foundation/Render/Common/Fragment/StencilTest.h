#pragma once
#include "Graphic/GLAPI/macros.h"
#include <cstdint>

namespace render
{
	/**
	*	Ä£°å²âÊÔ
	*/
	class StencilTest
	{
	public:
		static void enable();
		static void disable();
		static bool isEnabled();

		static void setFunc(StencilFunction func, int ref, uint32_t mask);
		static void setFuncSeparate(FaceType type, StencilFunction func, int ref, uint32_t mask);

		static void setOp(StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass);
		static void setOpSeparate(FaceType type, StencilOpResult stencilFail, StencilOpResult depthFail, StencilOpResult depthPass);


		static void setMask(uint32_t mask);
		static void setMaskSeparate(FaceType type, uint32_t mask);
	};
}
