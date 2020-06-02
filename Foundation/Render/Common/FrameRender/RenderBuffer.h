#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
namespace render
{
	class RenderBuffer : public sys::Object
	{
	public:
		RenderBuffer();
		virtual ~RenderBuffer();
	public:
		bool isValid();

		uint32_t getRenderBufferID() const;

		void setRenderBufferTarget(RenderBufferTarget target);
		RenderBufferTarget getRenderBufferTarget() const;
	protected:
		void initRenderBuffer();
		void relaseRenderBuffer();
	private:
		uint32_t _renderBufferID = 0;
		RenderBufferTarget _renderBufferTarget = RenderBufferTarget::RENDERBUFFER;
	};
}