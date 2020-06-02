#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
namespace render
{
	/**
	*	帧缓存对象
	*/
	class FrameBuffer : public sys::Object
	{
	public:
		FrameBuffer();
		virtual ~FrameBuffer();
	public:
		/**
		*	帧缓存对象编号
		*/
		uint32_t getFrameBufferID() const;
		/**
		*	是否有效
		*/
		bool isValid();
		/**
		*	帧缓存类型
		*/
		void setFrameBufferTarget(FrameBufferTarget target);
		/**
		*	帧缓存类型
		*/
		FrameBufferTarget getFrameBufferTarget()const;
		/**
		*	绑定帧缓存对象
		*/
		void bindTarget();
		/**
		*	绑定帧缓存对象
		*/
		void setDrawBuffers(int n, const DrawBufferType* bufs);
	protected:
		void initFrameBuffer();
		void relaseFrameBuffer();
	private:
		/**
		*	帧缓存对象编号
		*/
		uint32_t _frameBufferID = 0;
		/**
		*	帧缓存类型
		*/
		FrameBufferTarget _frameBufferTarget = FrameBufferTarget::FRAMEBUFFER;
	};
}