#pragma once
#include "Graphic/GLAPI/macros.h"
#include "VertexArrayAttrib.h"

namespace render
{
	class VertexAttribPointer : public VertexArrayAttrib
	{
	public:
		VertexAttribPointer(uint32_t index, VertexArrayObject* obj);
		virtual ~VertexAttribPointer();
	public:
		/**
		*	设置顶点属性指针 双精度
		*/
		void setVertexAttribLPointer(int size, VertexAttribLPointerType type, int stride, const void* pointer);
		/**
		*	设置顶点属性指针 整形
		*/
		void setVertexAttribIPointer(int size, VertexAttribIPointerType type, int stride, const void* pointer);
		/**
		*	设置顶点属性指针
		*/
		void setVertexAttribPointer(int size, VertexAttribPointerType type, bool normalized, int stride, const void* pointer);
		/**
		*	设置顶点属性指针
		*/
		void setVertexAttribPointer(int size, VertexAttribPointerType type, bool normalized, int stride, uint32_t offset);
		/**
		*	设置顶点属性指针
		*/
		void setVertexAttribPointer(int size, VertexAttribPointerType type, int stride, uint32_t offset);
		/**
		*	设置顶点属性指针
		*/
		void setVertexAttribPointer(int size, VertexAttribPointerType type, uint32_t offset);
	private:
	};
}