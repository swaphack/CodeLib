#pragma once

#include "macros.h"

namespace render
{
	class GLTransformFeedback
	{
	public:
		static void bindTransformFeedback(uint32_t id);
	public:
		static void createTransformFeedbacks(int n, uint32_t* ids);
		static uint32_t createTransformFeedback();
		static void deleteTransformFeedbacks(int n, const uint32_t* ids);
		static void deleteTransformFeedback(uint32_t id);

		static bool isTransformFeedback(uint32_t id);
	public:
		static void drawTransformFeedback(DrawTransformFeedbackMode mode, uint32_t id);
		static void drawTransformFeedbackInstanced(DrawTransformFeedbackMode mode, uint32_t id, int primcount);
		static void drawTransformFeedbackStream(DrawTransformFeedbackMode mode, uint32_t id, uint32_t stream);
		static void drawTransformFeedbackStreamInstanced(DrawTransformFeedbackMode mode, uint32_t id, uint32_t stream, int primcount);


		static void beginTransformFeedback(TransformFeedbackPrimitiveMode mode);
		static void endTransformFeedback();
	public:
		static void genTransformFeedbacks(int n, uint32_t* ids);
		static void getTransformFeedback(uint32_t xfb, GetTransformFeedbackParameter pname, uint32_t index, int *param);
		static void getTransformFeedbackVarying(uint32_t program, uint32_t index, int bufSize, int *length, int *size, uint32_t *type, char *name);
		
	public:
		static void pauseTransformFeedback();
		static void resumeTransformFeedback();
	public:
		static void setTransformFeedbackBufferBase(uint32_t xfb, uint32_t index, uint32_t buffer);
		static void setTransformFeedbackBufferRange(uint32_t xfb, uint32_t index, uint32_t buffer, ptrdiff_t offset, int size);
		/**
		*	@param varyings 增加间隔 gl_SkipComponents1-4, 跳转到下个缓存gl_NextBuffer 
		*	GL_SEPARATE_ATTRIBS gl_NextBuffer 一个跳转
		*	GL_INTERLEAVED_ATTRIBS gl_NextBuffer 二个以上跳转
		*/
		static void setTransformFeedbackVaryings(uint32_t program, int count, const char* const* varyings, TransformFeedbackBufferMode mode);
	};
}