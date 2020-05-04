#pragma once

#include "macros.h"

namespace render
{
	class GLTransformFeedback
	{
	public:
		static void beginTransformFeedback(TransformFeedbackPrimitiveMode mode);
		static void bindTransformFeedback(uint32_t id);
		static void createTransformFeedbacks(int n, uint32_t* ids);
		static void deleteTransformFeedbacks(int n, const uint32_t* ids);
		static void drawTransformFeedback(DrawTransformFeedbackMode mode, uint32_t id);
		static void drawTransformFeedbackInstanced(DrawTransformFeedbackMode mode, uint32_t id, int primcount);
		static void drawTransformFeedbackStream(DrawTransformFeedbackMode mode, uint32_t id, uint32_t stream);
		static void drawTransformFeedbackStreamInstanced(DrawTransformFeedbackMode mode, uint32_t id, uint32_t stream, int primcount);
		static void endTransformFeedback();
		static void genTransformFeedbacks(int n, uint32_t* ids);
		static void getTransformFeedback(uint32_t xfb, GetTransformFeedbackParameter pname, uint32_t index, int *param);
		static void getTransformFeedbackVarying(uint32_t program, uint32_t index, int bufSize, int *length, int *size, uint32_t *type, char *name);
		static bool isTransformFeedback(uint32_t id);
		static void pauseTransformFeedback();
		static void resumeTransformFeedback();
		static void setTransformFeedbackBufferBase(uint32_t xfb, uint32_t index, uint32_t buffer);
		static void setTransformFeedbackBufferRange(uint32_t xfb, uint32_t index, uint32_t buffer, ptrdiff_t offset, int size);
		static void setTransformFeedbackVaryings(uint32_t program, int count, const char** varyings, TransformFeedbackBufferMode mode);
	};
}