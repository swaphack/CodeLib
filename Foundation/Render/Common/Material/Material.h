#pragma once

#include "system.h"

#include "mathlib.h"
#include "Common/Shader/ShaderProgramDelegate.h"
#include "macros.h"

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
	class MaterialSetting;

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
		ShaderProgram* getShaderProgram() const;
	public:
		/**
		*	材质信息
		*/
		void setMaterialDetail(sys::MaterialDetail* detail);
		/**
		*	材质信息
		*/
		sys::MaterialDetail* getMaterialDetail() const;
		/**
		*	材质配置
		*/
		MaterialSetting* getMaterialSetting() const;
	public:
		/**
		*	shader设置函数
		*/
		void setProgramFunc(const ShaderProgramFunc& func);
		/**
		*	执行函数
		*/ 
		void runProgramFunc();
	public:
		/**
		*	应用材质
		*/ 
		void applyMaterial();

		bool equals(const Material& material) const;
	public: // 设置Uniform
		void setUniform(const std::string& name, int value);
		void setUniform(const std::string& name, float value);
		void setUniform(const std::string& name, const math::Vector2& value);
		void setUniform(const std::string& name, const math::Vector3& value);
		void setUniform(const std::string& name, const math::Vector4& value);
		void setUniform(const std::string& name, const math::Matrix2x2& value);
		void setUniform(const std::string& name, const math::Matrix3x3& value);
		void setUniform(const std::string& name, const math::Matrix4x4& value);
	public:
		bool hasAttrib(const std::string& name) const;
		bool hasAttrib(const VertexDataType& type) const;
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
		/**
		*	shader参数配置
		*/
		MaterialSetting* _materialSetting = nullptr;
	};
}