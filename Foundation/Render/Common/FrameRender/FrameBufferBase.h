#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
namespace render
{
	/**
	*	帧缓存对象
	*/
	class FrameBufferBase : public sys::Object
	{
	public:
		FrameBufferBase();
		virtual ~FrameBufferBase();
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
		void bindFrameBuffer();
		/**
		*	绑定帧缓存对象
		*/
		void bindFrameBuffer(FrameBufferTarget target);
		/**
		*	解除帧缓存对象绑定
		*/
		void unbindFrameBuffer();
		/**
		*	选择要写入的缓存
		*/
		void setDrawBuffers(int n, const DrawBufferType* bufs);
		/**
		*	选择要写入的缓存
		*/
		void setDrawBuffer(DrawBufferType buf);
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