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
		void resize(uint32_t size, BufferDataUsage usage = BufferDataUsage::STATIC_DRAW);
		/**
		*	写入数据
		*/
		void writeVertexAttrib(VertexAttribPointerType type, const void* value, uint32_t count = 1, uint32_t stride = 0);
		/**
		*	绑定
		*/
		void bindVertexArray();
		/**
		*	解绑
		*/
		void unbindVertexArray();
		/**
		*	激活字段
		*/
		void enableVertexArrayAttrib(uint32_t index);
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
		/**
		*	游标
		*/
		uint32_t _cursor = 0;
		/**
		*	索引
		*/
		uint32_t _index = 0;
	};
}
