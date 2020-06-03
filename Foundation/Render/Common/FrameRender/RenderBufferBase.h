#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
namespace render
{
	/**
	*	��Ⱦ����
	*/
	class RenderBufferBase : public sys::Object
	{
	public:
		RenderBufferBase();
		virtual ~RenderBufferBase();
	public:
		bool isValid();

		uint32_t getRenderBufferID() const;
		/**
		*	������Ⱦ����
		*/
		void setRenderBufferTarget(RenderBufferTarget target);
		/**
		*	��ȡ��Ⱦ����
		*/
		RenderBufferTarget getRenderBufferTarget() const;
		/**
		*	����Ⱦ�������
		*/
		void bindRenderBuffer();
		/**
		*	����Ⱦ�������
		*/
		void unbindRenderBuffer();
	protected:
		void initRenderBuffer();
		void relaseRenderBuffer();
	private:
		/**
		*	��Ⱦ������
		*/
		uint32_t _renderBufferID = 0;
		/**
		*	��Ⱦ����
		*/
		RenderBufferTarget _renderBufferTarget = RenderBufferTarget::RENDERBUFFER;
	};
}