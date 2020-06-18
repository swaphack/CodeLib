#pragma once

#include "mathlib.h"
#include "system.h"
#include "Common/Shader/ShaderProgramDelegate.h"
#include <cstdint>
#include <functional>

namespace render
{
	class XFBParticleNode;
	class VertexFragmentProgram;
	class TransformFeedback;
	class TransformFeedbackBuffer;
	class VertexArrayObject;
	class ArrayBuffer;

	struct XFBParticle : public sys::Object
	{
	public:
		VertexFragmentProgram* program = nullptr;
		ShaderProgramNFunc func = nullptr;

		TransformFeedback* xfbo = nullptr;
		TransformFeedbackBuffer* xfbb = nullptr;

		VertexArrayObject* vao = nullptr;
		ArrayBuffer* vbo = nullptr;
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