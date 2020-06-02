#pragma once

#include "RenderBuffer.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	class NoNamedRenderBuffer : public RenderBuffer
	{
	public:
		NoNamedRenderBuffer();
		virtual ~NoNamedRenderBuffer();
	public:
		void getParameter(RenderBufferParameter name, int* params);
		void setStorage(InternalImageFormat format, int width, int height);
		void setStorageMultisample(int samples, InternalImageFormat format, int width, int height);
	protected:
	private:
	};
}