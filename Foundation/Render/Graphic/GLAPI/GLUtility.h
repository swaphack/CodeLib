#pragma once

#include "macros.h"

namespace render
{
	class GLUtility
	{
	public:
		static const uint8_t* getString(StringName name);

		static void dispatchCompute(uint32_t numX, uint32_t numY, uint32_t numZ);
		static void dispatchComputeIndirect(GLintptr indirect);

		static GraphicsResetStatus getGraphicsResetStatus();

		static void getInternalFormat(GLenum target,
			GLenum internalformat,
			GLenum pname,
			GLsizei bufSize,
			GLint *params);
		static void getInternalFormat(GLenum target,
			GLenum internalformat,
			GLenum pname,
			GLsizei bufSize,
			GLint64 *params);

		static void getMultiSample(GLuint index,
			GLfloat *val);

		// @see MemoryBarrierBit
		static void setMemoryBarrier(GLbitfield barriers);
		// @see MemoryBarrierRegionBit
		static void setMemoryBarrierByRegion(GLbitfield barriers);
	};
}