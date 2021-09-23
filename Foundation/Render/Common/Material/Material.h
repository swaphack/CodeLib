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
		struct MaterialParameter
		{
			std::string name;
			std::string typeName;
		};

#define CREATE_UNIFORM(TYPE, FUNC)  \
void render::Material::setUniform(const std::string& name, const TYPE& value) \
{ \
	if (_shaderProgram == nullptr)  return; \
	auto pUniform = _shaderProgram->getUniform(name); \
	if (pUniform) pUniform->FUNC(value); \
}

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
		*	材质信息
		*/
		void setMaterialDetail(sys::MaterialDetail* detail);
		/**
		*	材质信息
		*/
		sys::MaterialDetail* getMaterialDetail() const;
	public:
		/**
		*	shader设置函数
		*/
		void setProgramFunc(const ShaderProgramFunc& func);
		/**
		*	执行函数
		*/ 
		void runProgramFunc();
		/**
		*	应用材质
		*/ 
		void applyMaterial();
	public: // 设置值
		/**
		*	应用材质
		*/
		void setUniform(const std::string& name, const math::Matrix4x4& value);
	protected:
		/**
		*	基础信息
		*/
		sys::MaterialDetail* _detail = nullptr;
		/**
		*	shader
		*/
		ShaderProgram* _shaderProgram = nullptr;
		/**
		*	shader设置函数
		*/
		ShaderProgramFunc _programFunc = nullptr;
	};
}