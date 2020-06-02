#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
namespace render
{
	/**
	*	֡�������
	*/
	class FrameBuffer : public sys::Object
	{
	public:
		FrameBuffer();
		virtual ~FrameBuffer();
	public:
		/**
		*	֡���������
		*/
		uint32_t getFrameBufferID() const;
		/**
		*	�Ƿ���Ч
		*/
		bool isValid();
		/**
		*	֡��������
		*/
		void setFrameBufferTarget(FrameBufferTarget target);
		/**
		*	֡��������
		*/
		FrameBufferTarget getFrameBufferTarget()const;
		/**
		*	��֡�������
		*/
		void bindTarget();
		/**
		*	��֡�������
		*/
		void setDrawBuffers(int n, const DrawBufferType* bufs);
	protected:
		void initFrameBuffer();
		void relaseFrameBuffer();
	private:
		/**
		*	֡���������
		*/
		uint32_t _frameBufferID = 0;
		/**
		*	֡��������
		*/
		FrameBufferTarget _frameBufferTarget = FrameBufferTarget::FRAMEBUFFER;
	};
}