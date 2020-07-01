#pragma once

#include "mathlib.h"
#include "system.h"
#include "Common/Shader/ShaderProgramDelegate.h"
#include <cstdint>
#include <functional>

namespace render
{
	class XFBObject;
	class VertexArrayBufferObject;
	class XFBParticleNode;

	struct XFBParticle : public sys::Object
	{
	public:
		XFBObject* xfb = nullptr;
		ShaderProgramNFunc func = nullptr;
		VertexArrayBufferObject* vao = nullptr;
	public:
		XFBParticle();
		virtual ~XFBParticle();
	public:
		void initXFBObject(int count);

		void doFunc(XFBParticleNode* node);
	protected:
		virtual void initXFB(int count);
		virtual void initVAO(int count);
	};

	struct XFBUpdateParticle : public XFBParticle
	{
	protected:
		virtual void initXFB(int count);
		virtual void initVAO(int count);
	};


	struct XFBRenderParticle : public XFBParticle
	{
	protected:
		virtual void initXFB(int count);
		virtual void initVAO(int count);
	};
}