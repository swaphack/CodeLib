#pragma once

#include "mathlib.h"
#include "system.h"
#include <cstdint>
#include <functional>

namespace render
{
	class ParticleSystem;
	class ShaderProgram;
	class TransformFeedbackObject;
	class TransformFeedbackBuffer;
	class VertexArrayObject;
	class ArrayBuffer;

	typedef std::function<void(ParticleSystem* node, ShaderProgram* program)> ParticleShaderFunc;

	struct ParticleXFbObject : public sys::Object
	{
	public:
		ShaderProgram* program = nullptr;
		ParticleShaderFunc func = nullptr;

		TransformFeedbackObject* xfbo = nullptr;
		TransformFeedbackBuffer* xfbb = nullptr;

		VertexArrayObject* vao = nullptr;
		ArrayBuffer* vbo = nullptr;
	public:
		ParticleXFbObject();
		virtual ~ParticleXFbObject();
	public:
		void initXFBObject(int count);

		void doFunc(ParticleSystem* node);
	protected:
		virtual void initXFB(int count);
		virtual void initVAO(int count);
	};

	struct ParticleUpdateXFbObject : public ParticleXFbObject
	{
	protected:
		virtual void initXFB(int count);
		virtual void initVAO(int count);
	};


	struct ParticleRenderXFbObject : public ParticleXFbObject
	{
	protected:
		virtual void initXFB(int count);
		virtual void initVAO(int count);
	};
}