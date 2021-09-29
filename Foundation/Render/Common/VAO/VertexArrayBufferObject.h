#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class VertexArrayObject;
	class ArrayBuffer;

	/**
	*	顶点数组缓存对象
	*/
	class VertexArrayBufferObject : public sys::Object
	{
	public:
		VertexArrayBufferObject();
		virtual ~VertexArrayBufferObject();
	public:
		/**
		*	重置大小
		*/
		void resizeBuffer(uint32_t size, BufferDataUsage usage = BufferDataUsage::STATIC_DRAW);
		/**
		*	设置数据
		*/
		void setSubBuffer(uint32_t offset, uint32_t size, const void* value);
		/**
		*	设置引用数据
		*/
		void setVertexAttribPointer(int index, uint32_t count, VertexAttribPointerType type, uint32_t stride, uint32_t offset);
		/**
		*	绑定
		*/
		void bindVertexArray();
		/**
		*	绑定
		*/
		void bindBuffer();
		/**
		*	解绑
		*/
		void unbindBuffer();
		/**
		*	解绑
		*/
		void unbindVertexArray();
		/**
		*	激活字段
		*/
		void enableVertexArrayAttrib(uint32_t index);
		/**
		*	失效字段
		*/
		void disableVertexArrayAttrib(uint32_t index);
	protected:
		/**
		*	初始化
		*/
		void initVABO();
		/**
		*	释放
		*/
		void releaseVABO();
	private:
		/**
		*	获取类型大小
		*/
		uint32_t getTypeSize(VertexAttribPointerType type);
	private:
		/**
		*	顶点数组对象
		*/
		VertexArrayObject* _vao = nullptr;
		/**
		*	数组缓存
		*/
		ArrayBuffer* _buffer = nullptr;
	};
}
