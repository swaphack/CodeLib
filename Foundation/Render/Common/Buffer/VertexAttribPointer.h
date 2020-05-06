#pragma once
#include "Graphic/GLAPI/macros.h"
#include "VAOAttrib.h"

namespace render
{
	class VertexAttribPointer : public VAOAttrib
	{
	public:
		VertexAttribPointer(uint32_t index, VertexArrayObject* obj);
		virtual~VertexAttribPointer();
	public:
		/**
		*	���ö�������ָ�� ˫����
		*/
		void setVertexAttribLPointer(int size, VertexAttribLPointerType type, int stride, const void* pointer);
		/**
		*	���ö�������ָ�� ����
		*/
		void setVertexAttribIPointer(int size, VertexAttribIPointerType type, int stride, const void* pointer);
		/**
		*	���ö�������ָ��
		*/
		void setVertexAttribPointer(int size, VertexAttribPointerType type, bool normalized, int stride, const void* pointer);
		/**
		*	���ö�������ָ��
		*/
		void setVertexAttribPointer(int size, VertexAttribPointerType type, bool normalized, int stride, uint32_t offset);
		/**
		*	���ö�������ָ��
		*/
		void setVertexAttribPointer(int size, VertexAttribPointerType type, int stride, uint32_t offset);
		/**
		*	���ö�������ָ��
		*/
		void setVertexAttribPointer(int size, VertexAttribPointerType type, uint32_t offset);
	protected:
	private:
	};
}