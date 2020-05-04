#pragma once

#include "Graphic/GLAPI/macros.h"
#include "system.h"
#include <cstdint>

namespace render
{
	/**
	*	缓存对象基础
	*/
	class BufferObjectBase : public sys::Object
	{
	public:
		BufferObjectBase();
		virtual ~BufferObjectBase();
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
		*	设置类型
		*/
		BufferTarget getBufferTarget() const;
	public:
		/**
		*	设置数据索引
		*/
		void setBufferBase(int index);
		/**
		*	设置数据范围
		*/
		void setBufferRange(int index, int offset, int size);
		/**
		*	获取关联数据
		*/
		void* getMapBuffer(AccessType type);
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