#pragma once

#include "Graphic/GLAPI/macros.h"
#include "system.h"
#include <cstdint>

namespace render
{
	/**
	*	缓存对象基础
	*/
	class BufferObject : public sys::Object
	{
	public:
		BufferObject();
		virtual ~BufferObject();
	public:
		/**
		*	缓存编号
		*/
		uint32_t getBufferID() const;
		/**
		*	设置类型
		*/
		void setBufferTarget(BufferTarget target);
		/**
		*	获取类型
		*/
		BufferTarget getBufferTarget() const;
		/**
		*	绑定类型
		*/
		void bindBuffer();
		/**
		*	是否有效
		*/
		bool isBuffer();
	public:
		/**
		*	设置数据索引
		*/
		void setBufferBase(uint32_t index);
		/**
		*	设置数据范围
		*/
		void setBufferRange(uint32_t index, int offset, int size);
		/**
		*	获取关联数据
		*/
		void* getMapBuffer(AccessType type);
		/**
		*	抛弃
		*/
		void invalidateBuffer();
		/**
		*	抛弃
		*/
		void invalidateBufferSubData(ptrdiff_t offset, ptrdiff_t length);
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
		/**
		*	缓存编号
		*/
		uint32_t _bufferID = 0;
		/**
		*	缓存类型
		*/
		BufferTarget _target;
	};
}