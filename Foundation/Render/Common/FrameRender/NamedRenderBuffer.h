#pragma once

#include "RenderBufferBase.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class NamedRenderBuffer : public RenderBufferBase
	{
	public:
		NamedRenderBuffer();
		virtual ~NamedRenderBuffer();
	public:
		void getParameter(RenderBufferParameter name, int* params);
		void setStorage(RenderBufferInternalFormat format, int width, int height);
		void setStorageMultisample(int samples, RenderBufferInternalFormat format, int width, int height);
	protected:
	private:
	};
}