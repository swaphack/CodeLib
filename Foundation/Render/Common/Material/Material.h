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
		void addVertexData(VertexDataType vat, const std::string& name);
		/**
		*	添加Attrib索引
		*/
		std::string getVertexName(VertexDataType vat) const;
		/**
		*	移除所有Attrib
		*/
		void removeVertexDatas();
	public:
		/**
		*	添加Uniform shader字段
		*/
		void addUniform(UniformType vut, const std::string& name);
		/**
		*	添加Attrib索引
		*/
		std::string getUniformName(UniformType vut) const;
		/**
		*	移除所有Attrib
		*/
		void removeUniformDatas();
	public:
		/**
		*	使用代码设置材质
		*/
		void beginApply(DrawTextureCache* textureCache);
		/**
		*	使用代码
		*/
		void endApply(DrawTextureCache* textureCache);
		/**
		*	使用shader设置材质
		*/
		void beginApplyWithShader(Node* node, Mesh* pMesh, DrawTextureCache* textureCache);
		/**
		*	使用shader
		*/
		void endApplyWithShader(Mesh* pMesh, DrawTextureCache* textureCache);
	protected:
		// 应用材质
		void applyMaterial();
		// 更新着色器uniform值
		void startUpdateShaderUniformValue(Node* node, DrawTextureCache* textureCache);
		// 更新着色器attrib值
		void startUpdateShaderVertexValue(Mesh* pMesh);

		void endUpdateShaderUniformValue(DrawTextureCache* textureCache);
		void endUpdateShaderVertexValue(Mesh* pMesh);
	protected:
		// 更新矩阵
		void updateMVPMatrixUniformValue(Node* node);
		// 更新单色光源，距离最近
		void updateNearestLightUniformValue(Node* node);
		// 更新所有光源
		void updateAllLightsUniformValue(Node* node);
		// 更新材质
		void updateMaterialUniformValue(DrawTextureCache* textureCache);
		// 更新纹理
		void updateTexturesUnifromValue(DrawTextureCache* textureCache);

	protected:
		void runProgramFunc();
	private:
		/**
		*	vertex
		*/
		std::map<VertexDataType, std::string> _vertexAttribIndices;
		/**
		*	Uniform
		*/
		std::map<UniformType, std::string> _vertexUniformIndices;
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