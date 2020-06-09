#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
namespace render
{
	/**
	*	֡�������
	*/
	class FrameBufferBase : public sys::Object
	{
	public:
		FrameBufferBase();
		virtual ~FrameBufferBase();
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
		void bindFrameBuffer();
		/**
		*	��֡�������
		*/
		void bindFrameBuffer(FrameBufferTarget target);
		/**
		*	���֡��������
		*/
		void unbindFrameBuffer();
		/**
		*	ѡ��Ҫд��Ļ���
		*/
		void setDrawBuffers(int n, const DrawBufferType* bufs);
		/**
		*	ѡ��Ҫд��Ļ���
		*/
		void setDrawBuffer(DrawBufferType buf);
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