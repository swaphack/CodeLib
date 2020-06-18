#pragma once

#include "Graphic/GLAPI/macros.h"
#include "system.h"
#include <cstdint>

namespace render
{
	/**
	*	缓存对象基础
	*/
	class Buffer : public sys::Object
	{
	public:
		Buffer();
		virtual ~Buffer();
	public:
		/**
		*	缓存编号
		*/
		uint32_t getBufferID() const;
	public:
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
		void bindBuffer(uint32_t bufferID) const;;
		/**
		*	绑定类型
		*/
		void bindBuffer() const;
		/**
		*	绑定类型
		*/
		void unbindBuffer() const;
		/**
		*	是否有效
		*/
		bool isBuffer() const;
	public:
		void bindBufferBase(BufferTarget target, uint32_t index);
		/**
		*	设置数据索引
		*/
		void bindBufferBase(uint32_t index);
		/**
		*	设置数据范围
		*/
		void getBufferRange(uint32_t index, ptrdiff_t offset, ptrdiff_t size);
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