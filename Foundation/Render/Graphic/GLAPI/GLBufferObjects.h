#pragma once

#include "macros.h"

namespace render
{
	class GLBufferObjects
	{
	public:
		static void bindBuffer(BufferTarget target, uint32_t buffer);
		static void bindBufferBase(BufferTarget target, uint32_t index, uint32_t buffer);
		static void bindBufferRange(BufferTarget target, uint32_t index, uint32_t buffer, ptrdiff_t offset, ptrdiff_t size);
		static void bindBuffersBase(BufferTarget target, uint32_t first, int count, const uint32_t* buffers);
		static void bindBuffersRange(BufferTarget target, uint32_t first, int count, const uint32_t* buffers, const ptrdiff_t* offset, const ptrdiff_t* size);
	public:
		static void bindVertexBuffer(uint32_t bindingindex, uint32_t buffer, ptrdiff_t offset, int stride);
		static void bindVertexArrayVertexBuffer(uint32_t vaojb, uint32_t bindingindex, uint32_t buffer, ptrdiff_t offset, int stride);
		static void bindVertexBuffers(uint32_t first, int count, const uint32_t* buffers, const ptrdiff_t *offsets, const int *strides);
		static void bindVertexArrayVertexBuffers(uint32_t vaojb, uint32_t first, int count, const uint32_t* buffers, const ptrdiff_t *offsets, const int *strides);
	public:
		static void setBufferData(BufferTarget target, ptrdiff_t size, const void* data, BufferDataUsage usage);
		static void setNamedBufferData(uint32_t buffer, ptrdiff_t size, const void* data, BufferDataUsage usage);
		// @see BufferStorageFlag
		static void setBufferStorage(BufferTarget target, ptrdiff_t size, const void* data, uint32_t flags);
		static void setBufferStorage(BufferTarget target, ptrdiff_t size, const void* data, BufferStorageFlag flag);

		static void setNamedBufferStorage(uint32_t buffer, ptrdiff_t size, const void* data, uint32_t flags);
		static void setNamedBufferStorage(uint32_t buffer, ptrdiff_t size, const void* data, BufferStorageFlag flag);

		static void setBufferSubData(BufferTarget target, ptrdiff_t offset, ptrdiff_t size, const void* data);
		static void setNamedBufferSubData(uint32_t buffer, ptrdiff_t offset, ptrdiff_t size, const void* data);
	public:
		static void clearBufferData(BufferTarget target, BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		static void clearNamedBufferData(uint32_t buffer, BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data);

		static void clearBufferSubData(BufferTarget target, BufferSizedInternalFormat internalformat, ptrdiff_t offset, ptrdiff_t size, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
		static void clearNamedBufferSubData(uint32_t buffer, BufferSizedInternalFormat internalformat, ptrdiff_t offset, ptrdiff_t size, BufferImageInternalFormat format, BufferImageDataType type, const void* data);
	public:
		static void copyBufferSubData(BufferTarget readTarget, BufferTarget writeTarget, ptrdiff_t readOffset, ptrdiff_t writeOffset, ptrdiff_t size);
		static void copyNamedBufferSubData(uint32_t readBuffer, uint32_t writeBuffer, ptrdiff_t readOffset, ptrdiff_t writeOffset, ptrdiff_t size);
	public:
		static void createBuffers(int n, uint32_t* buffers);
		static uint32_t createBuffer();

		static void createVertexArrays(int n, uint32_t* arrays);
		static uint32_t createVertexArray();
	public:
		static void deleteBuffer(uint32_t buffer);
		static void deleteBuffers(int n, uint32_t* buffers);
		static void disableVertexAttribArray(uint32_t index);
		static void disableVertexArrayAttrib(uint32_t vaobj, uint32_t index);
	public:
		// 按顺序绘制，不需要 indices
		static void drawArrays(DrawMode mode, int first, int count);
		static void drawArraysIndirect(DrawMode mode, const void* indirect);
		static void drawArraysInstanced(DrawMode mode, int first, int count, int primcount);
		static void drawArraysInstancedBaseInstance(DrawMode mode, int first, int count, int primcount, uint32_t baseinstance);
	public:
		static void drawElements(DrawMode mode, int count, IndexDataType type, const void* indices);
		static void drawElementsBaseVertex(DrawMode mode, int count, IndexDataType type, void* indices, int basevertex);
		static void drawElementsIndirect(DrawMode mode, DrawElementsIndirectType type, const void* indices);
		static void drawElementsInstanced(DrawMode mode, int count, IndexDataType type, const void* indices, int primcount);
		static void drawElementsInstancedBaseInstance(DrawMode mode, int count, IndexDataType type, const void* indices, int primcount, uint32_t baseinstance);
		static void drawElementsInstancedBaseVertex(DrawMode mode, int count, IndexDataType type, const void* indices, int primcount, int basevertex);
		static void drawElementsInstancedBaseVertexBaseInstance(DrawMode mode, int count, IndexDataType type, const void* indices, int primcount, int basevertex, uint32_t baseinstance);
		static void drawRangeElements(DrawMode mode, uint32_t start, uint32_t end, int count, IndexDataType type, const void* indices);
		static void drawRangeElementsBaseVertex(DrawMode mode, uint32_t start, uint32_t end, int count, IndexDataType type, void* indices, int basevertex);
	public:
		static void enableVertexAttribArray(uint32_t index);
		static void enableVertexArrayAttrib(uint32_t vaobj, uint32_t index);
	public:
		static void flushMappedBufferRange(BufferTarget target, ptrdiff_t offset, ptrdiff_t length);
		static void flushMappedNamedBufferRange(uint32_t buffer, ptrdiff_t offset, ptrdiff_t length);
	public:
		static uint32_t genBuffer();
		static void genBuffers(int n, uint32_t* buffers);
	public:
		static void getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int* params);
		static void getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int64_t* params);
		static void getNamedBufferParameter(uint32_t buffer, GetBufferParameter pname, int* params);
		static void getNamedBufferParameter(uint32_t buffer, GetBufferParameter pname, int64_t* params);

		static void getBufferPointer(BufferTarget target, BufferPointerParameter pname, void ** params);
		static void getBufferSubData(BufferTarget target, ptrdiff_t offset, ptrdiff_t size, void * data);
		static void getNamedBufferSubData(uint32_t buffer, ptrdiff_t offset, ptrdiff_t size, void * data);
	public:
		static void getVertexArrayIndexed(uint32_t vaobj, uint32_t index, GetVertexArrayIndexedParameter pname, int* param);
		static void getVertexArrayIndexed(uint32_t vaobj, uint32_t index, GetVertexArrayIndexedParameter64 pname, int64_t* param);

		static void getVertexArray(uint32_t vaobj, GetVertexArrayParameter pname, int* param);
	public:
		static void getVertexAttrib(uint32_t index, GetVertexAttribParameter pname, float* params);
		static void getVertexAttrib(uint32_t index, GetVertexAttribParameter pname, double* params);
		static void getVertexAttrib(uint32_t index, GetVertexAttribParameter pname, int* params);
		static void getVertexAttribI(uint32_t index, GetVertexAttribParameter pname, int* params);
		static void getVertexAttribUI(uint32_t index, GetVertexAttribParameter pname, uint32_t* params);
		static void getVertexAttribLD(uint32_t index, GetVertexAttribParameter pname, double* params);
	public:
		static void getVertexAttribPointer(uint32_t index, GetVertexAttribPointerParameter pname, void** pointer);
		static void invalidateBufferData(uint32_t buffer);
		static void invalidateBufferSubData(uint32_t buffer, ptrdiff_t offset, ptrdiff_t length);
		static bool isBuffer(uint32_t buffer);
	public:
		static void* getMapBuffer(BufferTarget target, AccessType access);
		static void* getMapNamedBuffer(GLuint buffer, AccessType access);
		//@see MapBufferRangeAccess
		static void* getMapBufferRange(BufferTarget target, ptrdiff_t offset, ptrdiff_t length, uint32_t access);
		static void* getMapBufferRange(BufferTarget target, ptrdiff_t offset, ptrdiff_t length, MapBufferRangeAccess access);

		static void* getMapNamedBufferRange(uint32_t buffer, ptrdiff_t offset, ptrdiff_t length, uint32_t access);
		static void* getMapNamedBufferRange(uint32_t buffer, ptrdiff_t offset, ptrdiff_t length, MapBufferRangeAccess access);
	public:
		static void multiDrawArrays(DrawMode mode, const int* first, const int* count, int drawcount);
		static void multiDrawArraysIndirect(DrawMode mode, const int* indirect, int primcount, int stride);
		static void multiDrawElements(DrawMode mode, const int* count, IndexDataType type, const void* const* indices, int drawcount);
		static void multiDrawElementsBaseVertex(DrawMode mode, int* count, IndexDataType type, void** indices, int primcount, int* basevertex);
		static void multiDrawElementsIndirect(DrawMode mode, DrawElementsIndirectType type, const int* indirect, int primcount, int stride);
	public:
		static void setPatchParameter(PatchParameter pname, int value);
		static void setPatchParameter(PatchParameter pname, const float* values);

		// 设置细分顶点数量
		static void setPatchVertices(int value);
		// 设置细分
		static void setPatchTessOuterLevel(float value[4]);
		// 设置细分
		static void setPatchTessInnerLevel(float value[2]);
	public:
		static void setPrimitiveRestartIndex(uint32_t index);
		static void setProvokingVertex(ProvokeMode mode);
	public:
		static bool unmapBuffer(BufferTarget target);
		static bool unmapNamedBuffer(uint32_t buffer);
	public:
		static void setVertexArrayElementBuffer(uint32_t vaobj, uint32_t buffer);
	public:
		static void setVertexAttrib(uint32_t index, double v0);
		static void setVertexAttrib(uint32_t index, double v0, double v1);
		static void setVertexAttrib(uint32_t index, double v0, double v1, double v2);
		static void setVertexAttrib(uint32_t index, double v0, double v1, double v2, double v3);

		static void setVertexAttrib(uint32_t index, float v0);
		static void setVertexAttrib(uint32_t index, float v0, float v1);
		static void setVertexAttrib(uint32_t index, float v0, float v1, float v2);
		static void setVertexAttrib(uint32_t index, float v0, float v1, float v2, float v3);


		static void setVertexAttrib(uint32_t index, int16_t v0);
		static void setVertexAttrib(uint32_t index, int16_t v0, int16_t v1);
		static void setVertexAttrib(uint32_t index, int16_t v0, int16_t v1, int16_t v2);
		static void setVertexAttrib(uint32_t index, int16_t v0, int16_t v1, int16_t v2, int16_t v3);

		static void setVertexAttrib(uint32_t index, int v0);
		static void setVertexAttrib(uint32_t index, int v0, int v1);
		static void setVertexAttrib(uint32_t index, int v0, int v1, int v2);
		static void setVertexAttrib(uint32_t index, int v0, int v1, int v2, int v3);


		static void setVertexAttrib(uint32_t index, uint32_t v0);
		static void setVertexAttrib(uint32_t index, uint32_t v0, uint32_t v1);
		static void setVertexAttrib(uint32_t index, uint32_t v0, uint32_t v1, uint32_t v2);
		static void setVertexAttrib(uint32_t index, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3);

		static void setVertexAttrib(uint32_t index, uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3);

		static void setVertexAttribL(uint32_t index, double v0);
		static void setVertexAttribL(uint32_t index, double v0, double v1);
		static void setVertexAttribL(uint32_t index, double v0, double v1, double v2);
		static void setVertexAttribL(uint32_t index, double v0, double v1, double v2, double v3);
	public:

		static void setVertexAttribArray1(uint32_t index, const double* v);
		static void setVertexAttribArray2(uint32_t index, const double* v);
		static void setVertexAttribArray3(uint32_t index, const double* v);
		static void setVertexAttribArray4(uint32_t index, const double* v);

		static void setVertexAttribArray1(uint32_t index, const float* v);
		static void setVertexAttribArray2(uint32_t index, const float* v);
		static void setVertexAttribArray3(uint32_t index, const float* v);
		static void setVertexAttribArray4(uint32_t index, const float* v);

		static void setVertexAttribArray1(uint32_t index, const int16_t* v);
		static void setVertexAttribArray2(uint32_t index, const int16_t* v);
		static void setVertexAttribArray3(uint32_t index, const int16_t* v);
		static void setVertexAttribArray4(uint32_t index, const int16_t* v);

		static void setVertexAttribArray1(uint32_t index, const int* v);
		static void setVertexAttribArray2(uint32_t index, const int* v);
		static void setVertexAttribArray3(uint32_t index, const int* v);
		static void setVertexAttribArray4(uint32_t index, const int* v);

		static void setVertexAttribArray1(uint32_t index, const uint32_t* v);
		static void setVertexAttribArray2(uint32_t index, const uint32_t* v);
		static void setVertexAttribArray3(uint32_t index, const uint32_t* v);
		static void setVertexAttribArray4(uint32_t index, const uint32_t* v);

		static void setVertexAttribArray4(uint32_t index, const int8_t* v);
		static void setVertexAttribArray4(uint32_t index, const uint8_t* v);
		static void setVertexAttribArray4(uint32_t index, const uint16_t* v);
	public:
		static void setVertexAttrib4N(uint32_t index, const int8_t* v);
		static void setVertexAttrib4N(uint32_t index, const int16_t* v);
		static void setVertexAttrib4N(uint32_t index, const int32_t* v);
		static void setVertexAttrib4N(uint32_t index, const uint8_t* v);
		static void setVertexAttrib4N(uint32_t index, const uint16_t* v);
		static void setVertexAttrib4N(uint32_t index, const uint32_t* v);
	public:
		static void setVertexAttribI4(uint32_t index, const int8_t* value);
		static void setVertexAttribI4(uint32_t index, const uint8_t* value);
		static void setVertexAttribI4(uint32_t index, const int16_t* value);
		static void setVertexAttribI4(uint32_t index, const uint16_t* value);
		static void setVertexAttribI4(uint32_t index, const int32_t* value);
		static void setVertexAttribI4(uint32_t index, const uint32_t* value);
	public:
		static void setVertexAttribL1(uint32_t index, const double* value);
		static void setVertexAttribL2(uint32_t index, const double* value);
		static void setVertexAttribL3(uint32_t index, const double* value);
		static void setVertexAttribL4(uint32_t index, const double* value);
	public:
		static void setVertexAttribP1(uint32_t index, VertexAttribPackType type, bool normalized, uint32_t value);
		static void setVertexAttribP2(uint32_t index, VertexAttribPackType type, bool normalized, uint32_t value);
		static void setVertexAttribP3(uint32_t index, VertexAttribPackType type, bool normalized, uint32_t value);
		static void setVertexAttribP4(uint32_t index, VertexAttribPackType type, bool normalized, uint32_t value);
	public:
		static void setVertexAttribBinding(uint32_t attribindex, uint32_t bindingindex);
		static void setVertexArrayAttribBinding(uint32_t vaobj, uint32_t attribindex, uint32_t bindingindex);
		static void setVertexAttribDivisor(uint32_t index, uint32_t divisor);
	public:
		static void setVertexAttribFormat(uint32_t attribindex, int size, VertexAttribFormatType type, bool normalized, uint32_t relativeoffset);
		static void setVertexAttribIFormat(uint32_t attribindex, int size, VertexAttribFormatType type, uint32_t relativeoffset);
		static void setVertexAttribLFormat(uint32_t attribindex, int size, VertexAttribFormatType type, uint32_t relativeoffset);

		static void setVertexArrayAttribFormat(uint32_t vaobj, uint32_t attribindex, int size, VertexAttribFormatType type, bool normalized, uint32_t relativeoffset);
		static void setVertexArrayAttribIFormat(uint32_t vaobj, uint32_t attribindex, int size, VertexAttribFormatType type, uint32_t relativeoffset);
		static void setVertexArrayAttribLFormat(uint32_t vaobj, uint32_t attribindex, int size, VertexAttribFormatType type, uint32_t relativeoffset);

		// size 1,2,3,4 GL_BGRA
		static void setVertexAttribPointer(uint32_t index, int size, VertexAttribPointerType type, bool normalized, int stride, const void* pointer);
		static void setVertexAttribIPointer(uint32_t index, int size, VertexAttribIPointerType type, int stride, const void* pointer);
		static void setVertexAttribLPointer(uint32_t index, int size, VertexAttribLPointerType type, int stride, const void* pointer);

		static void setVertexBindingDivisor(uint32_t bindingindex, int divisor);
		static void setVertexArrayBindingDivisor(uint32_t vaobj, uint32_t bindingindex, int divisor);
	};

}