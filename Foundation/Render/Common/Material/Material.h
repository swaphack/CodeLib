#pragma once

#include "system.h"

#include "mathlib.h"
#include "Common/Shader/ShaderProgramDelegate.h"

namespace sys
{
	class MaterialDetail;
}

namespace render
{
	class ShaderProgram;
	class VertexArrayObject;
	class Texture2D;
	class Mesh;
	class Node;
	class DrawTextureCache;

	class Material : public sys::Object
	{
	public:
		Material();
		virtual ~Material();
	public:
		/**
		*	shader
		*/
		void setShaderProgram(ShaderProgram* shaderProgram);
		/**
		*	shader
		*/
		ShaderProgram* getShaderProgram();
		/**
		*	������Ϣ
		*/
		void setMaterialDetail(sys::MaterialDetail* detail);
		/**
		*	������Ϣ
		*/
		sys::MaterialDetail* getMaterialDetail() const;
	public:
		/**
		*	shader���ú���
		*/
		void setProgramFunc(const ShaderProgramFunc& func);
		/**
		*	ִ�к���
		*/ 
		void runProgramFunc();
		/**
		*	Ӧ�ò���
		*/ 
		void applyMaterial();
	protected:
		/**
		*	������Ϣ
		*/
		sys::MaterialDetail* _detail = nullptr;
		/**
		*	shader
		*/
		ShaderProgram* _shaderProgram = nullptr;
		/**
		*	shader���ú���
		*/
		ShaderProgramFunc _programFunc = nullptr;
	};
}