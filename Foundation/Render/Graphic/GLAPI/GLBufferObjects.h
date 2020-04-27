#pragma once

#include "macros.h"

namespace render
{
	class GLBufferObjects
	{
	public:
		static void bindBuffer(BufferTarget target, uint32_t buffer);
		static void bindBufferBase(BufferTarget target, uint32_t index, uint32_t buffer);
		static void bindBufferRange(BufferTarget target, uint32_t index, uint32_t buffer, GLintptr offset, GLsizeiptr size);
		static void bindBuffersBase(BufferTarget target, uint32_t first, int count,  const uint32_t* buffers);
		static void bindBuffersRange(BufferTarget target, uint32_t first, int count, const uint32_t* buffers, const GLintptr* offset, const GLsizeiptr* size);

		static void bindVertexBuffer(uint32_t bindingindex, uint32_t buffer, GLintptr offset, int stride);
		static void bindVertexBuffers(uint32_t first, int count, const uint32_t* buffers, const GLintptr *offsets, const int *strides);
		static void bufferData(BufferTarget target, GLsizeiptr size, const void* data, BufferDataUsage usage);
		// @see BufferStorageFlag
		static void bufferStorage(BufferTarget target, GLsizeiptr size, const void* data, GLbitfield flags);
		/*
			static void bufferSubData
			static void glClearBufferData
			static void glClearBufferSubData
			static void glCopyBufferSubData
			static void glCreateBuffers
			static void glCreateVertexArrays
			static void glDeleteBuffers
			static void glDisableVertexAttribArray
			static void glDrawArrays
			static void glDrawArraysIndirect
			static void glDrawArraysInstanced
			static void glDrawArraysInstancedBaseInstance
			static void glDrawElements
			static void glDrawElementsBaseVertex
			static void glDrawElementsIndirect
			static void glDrawElementsInstanced
			static void glDrawElementsInstancedBaseInstance
			static void glDrawElementsInstancedBaseVertex
			static void glDrawElementsInstancedBaseVertexBaseInstance
			static void glDrawRangeElements
			static void glDrawRangeElementsBaseVertex
			static void glEnableVertexAttribArray
			static void glFlushMappedBufferRange
			static void glGenBuffers
			static void glGetBufferParameter
			static void glGetBufferParameteriv
			static void glGetBufferPointerv
			static void glGetBufferSubData
			static void glGetVertexArrayIndexed
			static void glGetVertexArrayiv
			static void glGetVertexAttrib
			static void glGetVertexAttribPointerv
			static void glInvalidateBufferData
			static void glInvalidateBufferSubData
			static void glIsBuffer
			static void glMapBuffer
			static void glMapBufferRange
			static void glMultiDrawArrays
			static void glMultiDrawArraysIndirect
			static void glMultiDrawElements
			static void glMultiDrawElementsBaseVertex
			static void glMultiDrawElementsIndirect
			static void glPatchParameter
			static void glPrimitiveRestartIndex
			static void glProvokingVertex
			static void glUnmapBuffer
			static void glVertexArrayElementBuffer
			static void glVertexAttrib
			static void glVertexAttribBinding
			static void glVertexAttribDivisor
			static void glVertexAttribFormat
			static void glVertexAttribPointer
			static void glVertexBindingDivisor
			*/
	};

}