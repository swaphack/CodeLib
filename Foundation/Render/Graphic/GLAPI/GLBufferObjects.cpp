#include "GLBufferObjects.h"

using namespace render;

void GLBufferObjects::bindBuffer(BufferTarget target, uint32_t buffer)
{
	glBindBuffer((GLenum)target, buffer);
}

void GLBufferObjects::bindBufferBase(BufferTarget target, uint32_t index, uint32_t buffer)
{
	glBindBufferBase((GLenum)target, index, buffer);
}

void GLBufferObjects::bindBufferRange(BufferTarget target, uint32_t index, uint32_t buffer, GLintptr offset, GLsizeiptr size)
{
	glBindBufferRange((GLenum)target, index, buffer, offset, size);
}

void GLBufferObjects::bindBuffersBase(BufferTarget target, uint32_t first, int count, const uint32_t* buffers)
{
	glBindBuffersBase((GLenum)target, first, count, buffers);
}

void GLBufferObjects::bindBuffersRange(BufferTarget target, uint32_t first, int count, const uint32_t* buffers, const GLintptr* offset, const GLsizeiptr* size)
{
	glBindBuffersRange((GLenum)target, first, count, buffers, offset, size);
}

void GLBufferObjects::bindVertexBuffer(uint32_t bindingindex, uint32_t buffer, GLintptr offset, int stride)
{
	glBindVertexBuffer(bindingindex, buffer, offset, stride);
}

void GLBufferObjects::bindVertexArrayVertexBuffer(uint32_t vaojb, uint32_t bindingindex, uint32_t buffer, GLintptr offset, int stride)
{
	glVertexArrayVertexBuffer(vaojb, bindingindex, buffer, offset, stride);
}

void GLBufferObjects::bindVertexBuffers(uint32_t first, int count, const uint32_t* buffers, const GLintptr *offsets, const int *strides)
{
	glBindVertexBuffers(first, count, buffers, offsets, strides);
}

void GLBufferObjects::bindVertexArrayVertexBuffers(uint32_t vaojb, uint32_t first, int count, const uint32_t* buffers, const GLintptr *offsets, const int *strides)
{
	glVertexArrayVertexBuffers(vaojb, first, count, buffers, offsets, strides);
}

void GLBufferObjects::setBufferData(BufferTarget target, GLsizeiptr size, const void* data, BufferDataUsage usage)
{
	glBufferData((GLenum)target, size, data, (GLenum)usage);
}

void GLBufferObjects::setNamedBufferData(uint32_t buffer, GLsizeiptr size, const void* data, BufferDataUsage usage)
{
	glNamedBufferData(buffer, size, data, (GLenum)usage);
}

void GLBufferObjects::setBufferStorage(BufferTarget target, GLsizeiptr size, const void* data, GLbitfield flags)
{
	glBufferStorage((GLenum)target, size, data, flags);
}

void GLBufferObjects::setNamedBufferStorage(uint32_t buffer, GLsizeiptr size, const void* data, GLbitfield flags)
{
	glNamedBufferStorage(buffer, size, data, flags);
}

void GLBufferObjects::setBufferSubData(BufferTarget target, GLintptr offset, GLsizeiptr size, const void* data)
{
	glBufferSubData((GLenum)target, offset, size, data);
}

void GLBufferObjects::setNamedBufferSubData(uint32_t buffer, GLintptr offset, GLsizeiptr size, const void* data)
{
	glNamedBufferSubData(buffer, offset, size, data);
}

void GLBufferObjects::clearBufferData(BufferTarget target, BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	glClearBufferData((GLenum)target, (GLenum)internalformat, (GLenum)format, (GLenum)type, data);
}

void GLBufferObjects::clearNamedBufferData(uint32_t buffer, BufferSizedInternalFormat internalformat, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	glClearNamedBufferData(buffer, (GLenum)internalformat, (GLenum)format, (GLenum)type, data);
}

void GLBufferObjects::clearBufferSubData(BufferTarget target, BufferSizedInternalFormat internalformat, GLintptr offset, GLsizeiptr size, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	glClearBufferSubData((GLenum)target, (GLenum)internalformat, offset, size, (GLenum)format, (GLenum)type, data);
}

void GLBufferObjects::clearNamedBufferSubData(uint32_t buffer, BufferSizedInternalFormat internalformat, GLintptr offset, GLsizeiptr size, BufferImageInternalFormat format, BufferImageDataType type, const void* data)
{
	glClearNamedBufferSubData(buffer, (GLenum)internalformat, offset, size, (GLenum)format, (GLenum)type, data);
}

void GLBufferObjects::copyBufferSubData(BufferTarget readTarget, BufferTarget writeTarget, GLintptr readOffset, GLintptr writeOffset, GLintptr size)
{
	glCopyBufferSubData((GLenum)readTarget, (GLenum)writeTarget, readOffset, writeOffset, size);
}

void GLBufferObjects::copyNamedBufferSubData(uint32_t readBuffer, uint32_t writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLintptr size)
{
	glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size);
}

void GLBufferObjects::createBuffers(int n, uint32_t* buffers)
{
	glCreateBuffers(n, buffers);
}

void GLBufferObjects::createVertexArrays(int n, uint32_t* arrays)
{
	glCreateVertexArrays(n, arrays);
}

void GLBufferObjects::deleteBuffers(int n, uint32_t* buffers)
{
	glDeleteBuffers(n, buffers);
}

void GLBufferObjects::disableVertexAttribArray(uint32_t index)
{
	glDisableVertexAttribArray(index);
}

void GLBufferObjects::disableVertexArrayAttrib(uint32_t vaobj, uint32_t index)
{
	glDisableVertexArrayAttrib(vaobj, index);
}

void GLBufferObjects::drawArrays(DrawMode mode, int first, int count)
{
	glDrawArrays((GLenum)mode, first, count);
}

void GLBufferObjects::drawArraysIndirect(DrawMode mode, const void* indirect)
{
	glDrawArraysIndirect((GLenum)mode, indirect);
}

void GLBufferObjects::drawArraysInstanced(DrawMode mode, int first, int count, int primcount)
{
	glDrawArraysInstanced((GLenum)mode, first, count, primcount);
}

void GLBufferObjects::drawArraysInstancedBaseInstance(DrawMode mode, int first, int count, int primcount, uint32_t baseinstance)
{
	glDrawArraysInstancedBaseInstance((GLenum)mode, first, count, primcount, baseinstance);
}

void GLBufferObjects::drawElements(DrawMode mode, int count, IndexDataType type, const void* indices)
{
	glDrawElements((GLenum)mode, count, (GLenum)type, indices);
}

void GLBufferObjects::drawElementsBaseVertex(DrawMode mode, int count, IndexDataType type, void* indices, int basevertex)
{
	glDrawElementsBaseVertex((GLenum)mode, count, (GLenum)type, indices, basevertex);
}

void GLBufferObjects::drawElementsIndirect(DrawMode mode, DrawElementsIndirectType type, const void* indices)
{
	glDrawElementsIndirect((GLenum)mode, (GLenum)type, indices);
}

void GLBufferObjects::drawElementsInstanced(DrawMode mode, int count, IndexDataType type, const void* indices, int primcount)
{
	glDrawElementsInstanced((GLenum)mode, count, (GLenum)type, indices, primcount);
}

void GLBufferObjects::drawElementsInstancedBaseInstance(DrawMode mode, int count, IndexDataType type, const void* indices, int primcount, uint32_t baseinstance)
{
	glDrawElementsInstancedBaseInstance((GLenum)mode, count, (GLenum)type, indices, primcount, baseinstance);
}

void GLBufferObjects::drawElementsInstancedBaseVertex(DrawMode mode, int count, IndexDataType type, const void* indices, int primcount, int basevertex)
{
	glDrawElementsInstancedBaseVertex((GLenum)mode, count, (GLenum)type, indices, primcount, basevertex);
}

void GLBufferObjects::drawElementsInstancedBaseVertexBaseInstance(DrawMode mode, int count, IndexDataType type, const void* indices, int primcount, int basevertex, uint32_t baseinstance)
{
	glDrawElementsInstancedBaseVertexBaseInstance((GLenum)mode, count, (GLenum)type, indices, primcount, basevertex, baseinstance);
}

void GLBufferObjects::drawRangeElements(DrawMode mode, uint32_t start, uint32_t end, int count, IndexDataType type, const void* indices)
{
	glDrawRangeElements((GLenum)mode, start, end, count, (GLenum)type, indices);
}

void GLBufferObjects::drawRangeElementsBaseVertex(DrawMode mode, uint32_t start, uint32_t end, int count, IndexDataType type, void* indices, int basevertex)
{
	glDrawRangeElementsBaseVertex((GLenum)mode, start, end, count, (GLenum)type, indices, basevertex);
}

void GLBufferObjects::enableVertexAttribArray(uint32_t index)
{
	glEnableVertexAttribArray(index);
}

void GLBufferObjects::enableVertexArrayAttrib(uint32_t vaobj, uint32_t index)
{
	glEnableVertexArrayAttrib(vaobj, index);
}

void GLBufferObjects::flushMappedBufferRange(BufferTarget target, GLintptr offset, GLsizeiptr length)
{
	glFlushMappedBufferRange((GLenum)target, offset, length);
}

void GLBufferObjects::flushMappedNamedBufferRange(uint32_t buffer, GLintptr offset, GLsizeiptr length)
{
	glFlushMappedNamedBufferRange(buffer, offset, length);
}

void GLBufferObjects::genBuffers(int n, uint32_t* buffers)
{
	glGenBuffers(n, buffers);
}

void GLBufferObjects::getBufferParameter(BufferTarget target, BufferParameter pname, int* params)
{
	glGetBufferParameteriv((GLenum)target, (GLenum)pname, params);
}

void GLBufferObjects::getBufferPointer(BufferTarget target, BufferPointerParameter pname, void ** params)
{
	glGetBufferPointerv((GLenum)target, (GLenum)pname, params);
}

void GLBufferObjects::getBufferSubData(BufferTarget target, GLintptr offset, GLsizeiptr size, void * data)
{
	glGetBufferSubData((GLenum)target, offset, size, data);
}

void GLBufferObjects::getNamedBufferSubData(uint32_t buffer, GLintptr offset, GLsizeiptr size, void * data)
{
	glGetNamedBufferSubData(buffer, offset, size, data);
}

void GLBufferObjects::getVertexArrayIndexed(uint32_t vaobj, uint32_t index, GetVertexArrayIndexedParameter pname, int* param)
{
	glGetVertexArrayIndexediv(vaobj, index, (GLenum)pname, param);
}

void GLBufferObjects::getVertexArray(uint32_t vaobj, GetVertexArrayParameter pname, int* param)
{
	glGetVertexArrayiv(vaobj, (GLenum)pname, param);
}

void GLBufferObjects::getVertexAttrib(uint32_t index, GetVertexAttribParameter pname, float* params)
{
	glGetVertexAttribfv(index, (GLenum)pname, params);
}

void GLBufferObjects::getVertexAttrib(uint32_t index, GetVertexAttribParameter pname, int* params)
{
	glGetVertexAttribiv(index, (GLenum)pname, params);
}

void GLBufferObjects::getVertexAttribI(uint32_t index, GetVertexAttribParameter pname, int* params)
{
	glGetVertexAttribIiv(index, (GLenum)pname, params);
}

void GLBufferObjects::getVertexAttribUI(uint32_t index, GetVertexAttribParameter pname, uint32_t* params)
{
	glGetVertexAttribIuiv(index, (GLenum)pname, params);
}

void GLBufferObjects::getVertexAttribLD(uint32_t index, GetVertexAttribParameter pname, double* params)
{
	glGetVertexAttribLdv(index, (GLenum)pname, params);
}

void GLBufferObjects::getVertexAttribPointer(uint32_t index, GetVertexAttribPointerParameter pname, void** pointer)
{
	glGetVertexAttribPointerv(index, (GLenum)pname, pointer);
}

void GLBufferObjects::invalidateBufferData(uint32_t buffer)
{
	glInvalidateBufferData(buffer);
}

void GLBufferObjects::invalidateBufferSubData(uint32_t buffer, GLintptr offset, GLsizeiptr length)
{
	glInvalidateBufferSubData(buffer, offset, length);
}

bool GLBufferObjects::isBuffer(uint32_t buffer)
{
	return glIsBuffer(buffer) == GL_TRUE;
}

void GLBufferObjects::setMapBuffer(BufferTarget target, AccessType access)
{
	glMapBuffer((GLenum)target, (GLenum)access);
}

void GLBufferObjects::setMapNamedBuffer(GLuint buffer, AccessType access)
{
	glMapNamedBuffer(buffer, (GLenum)access);
}

void GLBufferObjects::setMapBufferRange(BufferTarget target, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	glMapBufferRange((GLenum)target, offset, length, access);
}

void GLBufferObjects::setMapNamedBufferRange(uint32_t buffer, GLintptr offset, GLsizeiptr length, GLbitfield access)
{
	glMapNamedBufferRange(buffer, offset, length, access);
}

void GLBufferObjects::multiDrawArrays(DrawMode mode, const int* first, const int* count, int drawcount)
{
	glMultiDrawArrays((GLenum)mode, first, count, drawcount);
}

void GLBufferObjects::multiDrawArraysIndirect(DrawMode mode, const int* indirect, int primcount, int stride)
{
	glMultiDrawArraysIndirect((GLenum)mode, indirect, primcount, stride);
}

void GLBufferObjects::multiDrawElements(DrawMode mode, const int* count, IndexDataType type, const void* const* indices, int drawcount)
{
	glMultiDrawElements((GLenum)mode, count, (GLenum)type, indices, drawcount);
}

void GLBufferObjects::multiDrawElementsBaseVertex(DrawMode mode, int* count, IndexDataType type, void** indices, int primcount, int* basevertex)
{
	glMultiDrawElementsBaseVertex((GLenum)mode, count, (GLenum)type, indices, primcount, basevertex);
}

void GLBufferObjects::multiDrawElementsIndirect(DrawMode mode, DrawElementsIndirectType type, const int* indirect, int primcount, int stride)
{
	glMultiDrawElementsIndirect((GLenum)mode, (GLenum)type, indirect, primcount, stride);
}

void GLBufferObjects::patchParameter(PatchParameter pname, int value)
{
	glPatchParameteri((GLenum)pname, value);
}

void GLBufferObjects::setPrimitiveRestartIndex(uint32_t index)
{
	glPrimitiveRestartIndex(index);
}

void GLBufferObjects::setProvokingVertex(ProvokeMode mode)
{
	glProvokingVertex((GLenum)mode);
}

void GLBufferObjects::unmapBuffer(BufferTarget target)
{
	glUnmapBuffer((GLenum)target);
}

void GLBufferObjects::unmapNamedBuffer(uint32_t buffer)
{
	glUnmapNamedBuffer(buffer);
}

void GLBufferObjects::setVertexArrayElementBuffer(uint32_t vaobj, uint32_t buffer)
{
	glVertexArrayElementBuffer(vaobj, buffer);
}

void GLBufferObjects::setVertexAttribBinding(uint32_t attribindex, uint32_t bindingindex)
{
	glVertexAttribBinding(attribindex, bindingindex);
}

void GLBufferObjects::setVertexArrayAttribBinding(uint32_t vaobj, uint32_t attribindex, uint32_t bindingindex)
{
	glVertexArrayAttribBinding(vaobj, attribindex, bindingindex);
}

void GLBufferObjects::setVertexAttribDivisor(uint32_t index, uint32_t divisor)
{
	glVertexAttribDivisor(index, divisor);
}

void GLBufferObjects::setVertexAttribFormat(uint32_t attribindex, int size, VertexAttribFormatType type, bool normalized, uint32_t relativeoffset)
{
	glVertexAttribFormat(attribindex, size, (GLenum)type, normalized ? GL_TRUE : GL_FALSE, relativeoffset);
}

void GLBufferObjects::setVertexAttribIFormat(uint32_t attribindex, int size, VertexAttribFormatType type, uint32_t relativeoffset)
{
	glVertexAttribIFormat(attribindex, size, (GLenum)type, relativeoffset);
}

void GLBufferObjects::setVertexAttribLFormat(uint32_t attribindex, int size, VertexAttribFormatType type, uint32_t relativeoffset)
{
	glVertexAttribLFormat(attribindex, size, (GLenum)type, relativeoffset);
}

void GLBufferObjects::setVertexArrayAttribFormat(uint32_t vaobj, uint32_t attribindex, int size, VertexAttribFormatType type, bool normalized, uint32_t relativeoffset)
{
	glVertexArrayAttribFormat(vaobj, attribindex, size, (GLenum)type, normalized ? GL_TRUE : GL_FALSE, relativeoffset);
}

void GLBufferObjects::setVertexArrayAttribIFormat(uint32_t vaobj, uint32_t attribindex, int size, VertexAttribFormatType type, uint32_t relativeoffset)
{
	glVertexArrayAttribIFormat(vaobj, attribindex, size, (GLenum)type, relativeoffset);
}

void GLBufferObjects::setVertexArrayAttribLFormat(uint32_t vaobj, uint32_t attribindex, int size, VertexAttribFormatType type, uint32_t relativeoffset)
{
	glVertexArrayAttribLFormat(vaobj, attribindex, size, (GLenum)type, relativeoffset);
}

void GLBufferObjects::setVertexAttribPointer(uint32_t index, int size, VertexAttribPointerType type, bool normalized, int stride, const void* pointer)
{
	glVertexAttribPointer(index, size, (GLenum)type, normalized ? GL_TRUE : GL_FALSE, stride, pointer);
}

void GLBufferObjects::setVertexAttribIPointer(uint32_t index, int size, VertexAttribIPointerType type, int stride, const void* pointer)
{
	glVertexAttribIPointer(index, size, (GLenum)type, stride, pointer);
}

void GLBufferObjects::setVertexAttribLPointer(uint32_t index, int size, VertexAttribLPointerType type, int stride, const void* pointer)
{
	glVertexAttribLPointer(index, size, (GLenum)type, stride, pointer);
}

void GLBufferObjects::setVertexBindingDivisor(uint32_t bindingindex, int divisor)
{
	glVertexBindingDivisor(bindingindex, divisor);
}

void GLBufferObjects::setVertexArrayBindingDivisor(uint32_t vaobj, uint32_t bindingindex, int divisor)
{
	glVertexArrayBindingDivisor(vaobj, bindingindex, divisor);
}

void GLBufferObjects::patchParameter(PatchParameter pname, const float* values)
{
	glPatchParameterfv((GLenum)pname, values);
}

void GLBufferObjects::getVertexAttrib(uint32_t index, GetVertexAttribParameter pname, double* params)
{
	glGetVertexAttribdv(index, (GLenum)pname, params);
}

void GLBufferObjects::getVertexArrayIndexed(uint32_t vaobj, uint32_t index, GetVertexArrayIndexedParameter64 pname, int64_t* param)
{
	glGetVertexArrayIndexed64iv(vaobj, index, (GLenum)pname, param);
}

void GLBufferObjects::getNamedBufferParameter(uint32_t buffer, BufferParameter pname, int* params)
{
	glGetNamedBufferParameteriv(buffer, (GLenum)pname, params);
}

void GLBufferObjects::getBufferParameter(GetBufferTarget target, GetBufferParameter pname, int* params)
{
	glGetBufferParameteriv((GLenum)target, (GLenum)pname, params);
}

void GLBufferObjects::getNamedBufferParameter(uint32_t buffer, BufferParameter pname, int64_t* params)
{
	glGetNamedBufferParameteri64v(buffer, (GLenum)pname, params);
}

void GLBufferObjects::getBufferParameter(BufferTarget target, BufferParameter pname, int64_t* params)
{
	glGetBufferParameteri64v((GLenum)target, (GLenum)pname, params);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, float v0)
{
	glVertexAttrib1f(index, v0);
}

void render::GLBufferObjects::setVertexAttribL(uint32_t index, double v0)
{
	glVertexAttrib1d(index, v0);
}

void render::GLBufferObjects::setVertexAttribArray1(uint32_t index, const float* v)
{
	glVertexAttrib1fv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray2(uint32_t index, const float* v)
{
	glVertexAttrib2fv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray3(uint32_t index, const float* v)
{
	glVertexAttrib3fv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray4(uint32_t index, const float* v)
{
	glVertexAttrib4fv(index, v);
}

void render::GLBufferObjects::setVertexAttrib4N(uint32_t index, const int8_t* v)
{
	glVertexAttrib4Nbv(index, v);
}

void render::GLBufferObjects::setVertexAttrib4N(uint32_t index, const uint32_t* v)
{
	glVertexAttrib4Nuiv(index, v);
}

void render::GLBufferObjects::setVertexAttrib4N(uint32_t index, const uint16_t* v)
{
	glVertexAttrib4Nusv(index, v);
}

void render::GLBufferObjects::setVertexAttrib4N(uint32_t index, const uint8_t* v)
{
	glVertexAttrib4Nubv(index, v);
}

void render::GLBufferObjects::setVertexAttrib4N(uint32_t index, const int32_t* v)
{
	glVertexAttrib4Niv(index, v);
}

void render::GLBufferObjects::setVertexAttrib4N(uint32_t index, const int16_t* v)
{
	glVertexAttrib4Nsv(index, v);
}

void render::GLBufferObjects::setVertexAttribI4(uint32_t index, const uint32_t* value)
{
	glVertexAttribI4uiv(index, value);
}

void render::GLBufferObjects::setVertexAttribI4(uint32_t index, const int32_t* value)
{
	glVertexAttribI4iv(index, value);
}

void render::GLBufferObjects::setVertexAttribI4(uint32_t index, const uint16_t* value)
{
	glVertexAttribI4usv(index, value);
}

void render::GLBufferObjects::setVertexAttribI4(uint32_t index, const int16_t* value)
{
	glVertexAttribI4sv(index, value);
}

void render::GLBufferObjects::setVertexAttribI4(uint32_t index, const uint8_t* value)
{
	glVertexAttribI4ubv(index, value);
}

void render::GLBufferObjects::setVertexAttribI4(uint32_t index, const int8_t* value)
{
	glVertexAttribI4bv(index, value);
}

void render::GLBufferObjects::setVertexAttribL1(uint32_t index, const double* value)
{
	glVertexAttribL1dv(index, value);
}

void render::GLBufferObjects::setVertexAttribL2(uint32_t index, const double* value)
{
	glVertexAttribL2dv(index, value);
}

void render::GLBufferObjects::setVertexAttribL3(uint32_t index, const double* value)
{
	glVertexAttribL3dv(index, value);
}

void render::GLBufferObjects::setVertexAttribL4(uint32_t index, const double* value)
{
	glVertexAttribL4dv(index, value);
}

void render::GLBufferObjects::setVertexAttribP1(uint32_t index, VertexAttribPackType type, bool normalized, uint32_t value)
{
	glVertexAttribP1ui(index, (GLenum)type, normalized ? GL_TRUE : GL_FALSE, value);
}

void render::GLBufferObjects::setVertexAttribP2(uint32_t index, VertexAttribPackType type, bool normalized, uint32_t value)
{
	glVertexAttribP2ui(index, (GLenum)type, normalized ? GL_TRUE : GL_FALSE, value);
}

void render::GLBufferObjects::setVertexAttribP3(uint32_t index, VertexAttribPackType type, bool normalized, uint32_t value)
{
	glVertexAttribP3ui(index, (GLenum)type, normalized ? GL_TRUE : GL_FALSE, value);
}

void render::GLBufferObjects::setVertexAttribP4(uint32_t index, VertexAttribPackType type, bool normalized, uint32_t value)
{
	glVertexAttribP4ui(index, (GLenum)type, normalized ? GL_TRUE : GL_FALSE, value);
}

void render::GLBufferObjects::setVertexAttribArray4(uint32_t index, const uint16_t* v)
{
	glVertexAttrib4usv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray4(uint32_t index, const uint32_t* v)
{
	glVertexAttrib4uiv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray4(uint32_t index, const uint8_t* v)
{
	glVertexAttrib4ubv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray4(uint32_t index, const int8_t* v)
{
	glVertexAttrib4bv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray4(uint32_t index, const int* v)
{
	glVertexAttrib4iv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray4(uint32_t index, const double* v)
{
	glVertexAttrib4dv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray4(uint32_t index, const int16_t* v)
{
	glVertexAttrib4sv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray3(uint32_t index, const uint32_t* v)
{
	glVertexAttribI3uiv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray3(uint32_t index, const int* v)
{
	glVertexAttribI3iv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray3(uint32_t index, const double* v)
{
	glVertexAttrib3dv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray3(uint32_t index, const int16_t* v)
{
	glVertexAttrib3sv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray2(uint32_t index, const uint32_t* v)
{
	glVertexAttribI2uiv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray2(uint32_t index, const int* v)
{
	glVertexAttribI2iv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray2(uint32_t index, const double* v)
{
	glVertexAttrib2dv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray2(uint32_t index, const int16_t* v)
{
	glVertexAttrib2sv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray1(uint32_t index, const uint32_t* v)
{
	glVertexAttribI2uiv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray1(uint32_t index, const int* v)
{
	glVertexAttribI2iv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray1(uint32_t index, const double* v)
{
	glVertexAttrib1dv(index, v);
}

void render::GLBufferObjects::setVertexAttribArray1(uint32_t index, const int16_t* v)
{
	glVertexAttrib1sv(index, v);
}

void render::GLBufferObjects::setVertexAttribL(uint32_t index, double v0, double v1, double v2, double v3)
{
	glVertexAttribL4d(index, v0, v1, v2, v3);
}

void render::GLBufferObjects::setVertexAttribL(uint32_t index, double v0, double v1, double v2)
{
	glVertexAttribL3d(index, v0, v1, v2);
}

void render::GLBufferObjects::setVertexAttribL(uint32_t index, double v0, double v1)
{
	glVertexAttribL2d(index, v0, v1);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3)
{
	glVertexAttribI4ui(index, v0, v1, v2, v3);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, int v0, int v1, int v2, int v3)
{
	glVertexAttribI4i(index, v0, v1, v2, v3);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3)
{
	glVertexAttrib4Nub(index, v0, v1, v2, v3);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, double v0, double v1, double v2, double v3)
{
	glVertexAttrib4d(index, v0, v1, v2, v3);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, int16_t v0, int16_t v1, int16_t v2, int16_t v3)
{
	glVertexAttrib4s(index, v0, v1, v2, v3);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, float v0, float v1, float v2, float v3)
{
	glVertexAttrib4f(index, v0, v1, v2, v3);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, uint32_t v0, uint32_t v1, uint32_t v2)
{
	glVertexAttribI3ui(index, v0, v1, v2);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, int v0, int v1, int v2)
{
	glVertexAttribI3i(index, v0, v1, v2);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, double v0, double v1, double v2)
{
	glVertexAttrib3d(index, v0, v1, v2);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, int16_t v0, int16_t v1, int16_t v2)
{
	glVertexAttrib3s(index, v0, v1, v2);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, float v0, float v1, float v2)
{
	glVertexAttrib3f(index, v0, v1, v2);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, uint32_t v0, uint32_t v1)
{
	glVertexAttribI2ui(index, v0, v1);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, int v0, int v1)
{
	glVertexAttribI2i(index, v0, v1);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, double v0, double v1)
{
	glVertexAttrib2d(index, v0, v1);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, int16_t v0, int16_t v1)
{
	glVertexAttrib2s(index, v0, v1);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, float v0, float v1)
{
	glVertexAttrib2f(index, v0, v1);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, uint32_t v0)
{
	glVertexAttribI1ui(index, v0);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, int v0)
{
	glVertexAttribI1i(index, v0);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, double v0)
{
	glVertexAttrib1d(index, v0);
}

void render::GLBufferObjects::setVertexAttrib(uint32_t index, int16_t v0)
{
	glVertexAttrib1s(index, v0);
}

uint32_t render::GLBufferObjects::genBuffer()
{
	uint32_t id;
	genBuffers(1, &id);
	return id;
}

void render::GLBufferObjects::deleteBuffer(uint32_t buffer)
{
	deleteBuffers(1, &buffer);
}
