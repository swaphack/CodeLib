#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
namespace render
{
	/**
	*	‰÷»æª∫¥Ê
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
		*	…Ë÷√‰÷»æ¿‡–Õ
		*/
		void setRenderBufferTarget(RenderBufferTarget target);
		/**
		*	ªÒ»°‰÷»æ¿‡–Õ
		*/
		RenderBufferTarget getRenderBufferTarget() const;
		/**
		*	∞Û∂®‰÷»æª∫¥Ê∂‘œÛ
		*/
		void bindRenderBuffer();
		/**
		*	∞Û∂®‰÷»æª∫¥Ê∂‘œÛ
		*/
		void unbindRenderBuffer();
	protected:
		void initRenderBuffer();
		void relaseRenderBuffer();
	private:
		/**
		*	‰÷»æª∫¥Ê±‡∫≈
		*/
		uint32_t _renderBufferID = 0;
		/**
		*	‰÷»æ¿‡–Õ
		*/
		RenderBufferTarget _renderBufferTarget = RenderBufferTarget::RENDERBUFFER;
	};
}