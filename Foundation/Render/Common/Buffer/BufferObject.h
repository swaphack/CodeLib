#pragma once

#include "Graphic/GLAPI/macros.h"
#include "system.h"
#include <cstdint>

namespace render
{
	class BufferObject : public sys::Object
	{
	public:
		BufferObject();
		virtual ~BufferObject();
	public:
		/**
		*	设置类型
		*/
		void setBufferTarget(BufferTarget target);
		/**
		*	绑定数据
		*/
		void setBufferData(int size, const void* data, BufferDataUsage usage);
		/**
		*	设置数据索引
		*/
		void setBufferBase(int index);
		/**
		*	设置数据范围
		*/
		void setBufferRange(int index, int offset, int size);
	protected:
		/**
		*	初始化
		*/
		void initBufferObject();
		/**
		*	释放
		*/
		void relaseBufferObject();
	private:
		uint32_t _bufferID = 0;
		BufferTarget _target;
	};
}