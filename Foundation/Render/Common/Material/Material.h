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
		*	������Ϣ
		*/
		void setMaterialDetail(sys::MaterialDetail* detail);
		/**
		*	������Ϣ
		*/
		sys::MaterialDetail* getMaterialDetail() const;
		/**
		*	��������
		*/
		MaterialSetting* getMaterialSetting() const;
	public:
		/**
		*	shader���ú���
		*/
		void setProgramFunc(const ShaderProgramFunc& func);
		/**
		*	ִ�к���
		*/ 
		void runProgramFunc();
	public:
		/**
		*	Ӧ�ò���
		*/ 
		void applyMaterial();

		bool equals(const Material& material) const;
	public: // ����Uniform
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
		/**
		*	shader��������
		*/
		MaterialSetting* _materialSetting = nullptr;
	};
}