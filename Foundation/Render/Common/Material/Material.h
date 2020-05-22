#pragma once

#include "system.h"

#include "mathlib.h"

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
	class Materials;

	enum class VertexAttribType
	{
		POSITION,
		COLOR,
		UV,
		UV1,
		UV2,
		UV3,
		UV4,
		NORMAL,
		BLEND_WEIGHT,
		BLEND_INDEX,
		MAX,
		UVS = UV,
	};

	// 统一变量
	enum class VertexUniformType
	{
		// 投影矩阵
		PROJECT_MATRIX,
		// 视图矩阵
		VIEW_MATRIX,
		// 模型矩阵
		MODEL_VIEW,
		// 环境纹理
		AMBIENT_TEXTURE,
		// 漫射纹理
		DIFFUSE_TEXTURE,
		// 高光纹理
		SPECULAR_TEXTURE,
	};

	class Material : public sys::Object
	{
	public:
		typedef std::function<void(ShaderProgram* program)> ShaderProgramFunc;
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
	public:
		/**
		*	添加Attrib shader in字段
		*/
		void addAttrib(VertexAttribType vat, const std::string& name);
		/**
		*	添加Attrib索引
		*/
		std::string getAttribIndex(VertexAttribType vat) const;
		/**
		*	移除所有Attrib
		*/
		void removeAttribIndices();
	public:
		/**
		*	添加Uniform shader字段
		*/
		void addUniform(VertexUniformType vut, const std::string& name);
		/**
		*	添加Attrib索引
		*/
		std::string getUniformIndex(VertexUniformType vut) const;
		/**
		*	移除所有Attrib
		*/
		void removeUniformIndices();
	public:
		// 应用材质
		void apply(Materials* mats);

		void beginApplyWithShader(Node* node, Mesh* pMesh, Materials* mats);
		void endApplyWithShader(Mesh* pMesh);
	protected:
		// 应用材质
		void applyMaterial();
		// 更新着色器uniform值
		void startUpdateShaderUniformValue(Node* node, Materials* mats);
		// 更新着色器attrib值
		void startUpdateShaderVertexValue(Mesh* pMesh);
		void endUpdateShaderUniformValue();
		void endUpdateShaderVertexValue(Mesh* pMesh);
	protected:
		void runProgramFunc();
	private:
		/**
		*	Attrib
		*/
		std::map<VertexAttribType, std::string> _vertexAttribIndices;
		/**
		*	Uniform
		*/
		std::map<VertexUniformType, std::string> _vertexUniformIndices;
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