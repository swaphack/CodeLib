#pragma once

#include "macros.h"
#include "mathlib.h"
#include <string>
#include <map>

namespace render
{
	class Node;
	class DrawTextureCache;
	class Mesh;
	class ShaderProgram;
	class Material;

	/**
	*	统一着色器应用
	*/
	class UniformShaderApply
	{
	public:
		UniformShaderApply();
		virtual ~UniformShaderApply();
	public:
		/**
		*	使用代码设置材质
		*/
		void beginApply(Material* pMaterial, DrawTextureCache* textureCache);
		/**
		*	使用代码
		*/
		void endApply(Material* pMaterial, DrawTextureCache* textureCache);
		/**
		*	使用shader设置材质
		*/
		void beginApplyWithShader(Node* node, ShaderProgram* program, Mesh* pMesh, Material* pMaterial, DrawTextureCache* textureCache);
		/**
		*	使用shader
		*/
		void endApplyWithShader(ShaderProgram* program, Mesh* pMesh, Material* pMaterial, DrawTextureCache* textureCache);
	public:
		// 开始更新着色器uniform值
		void startUpdateShaderUniformValue(Node* node, ShaderProgram* program, Mesh* pMesh, Material* pMaterial, DrawTextureCache* textureCache);
		// 结束更新着色器attrib值
		void startUpdateShaderVertexValue(ShaderProgram* program, Mesh* pMesh);
		// 开始更新着色器uniform值
		void endUpdateShaderUniformValue(ShaderProgram* program, Material* pMaterial, DrawTextureCache* textureCache);
		// 结束更新着色器attrib值
		void endUpdateShaderVertexValue(ShaderProgram* program, Mesh* pMesh);
	protected:
		// 更新矩阵
		void updateMVPMatrixUniformValue(Node* node, ShaderProgram* program);
		// 更新材质
		void updateMaterialUniformValue(ShaderProgram* program, Material* pMaterial, DrawTextureCache* textureCache);
		// 更新纹理
		void updateTexturesUnifromValue(ShaderProgram* program, Material* pMaterial, DrawTextureCache* textureCache);
	public:
		// 应用光照着色器
		void applyLightShader(Node* node, ShaderProgram* program);
	protected:
		// 更新单色光源，距离最近
		void updateNearestLightUniformValue(Node* node, ShaderProgram* program);
		// 更新所有光源
		void updateAllLightsUniformValue(Node* node, ShaderProgram* program);
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
		void setTempMatrix(const math::Matrix4x4& matrix);

		void reloadTempMatrix();

		math::Matrix4x4 getWorldMatrix(const Node* node);
	protected:
		/**
		*	vertex
		*/
		std::map<VertexDataType, std::string> _vertexAttribIndices;
		/**
		*	Uniform
		*/
		std::map<UniformType, std::string> _vertexUniformIndices;
		/**
		*	临时矩阵
		*/
		math::Matrix4x4 _tempMatrix;
	};

#define G_UNIFORMSHADERAPPLY sys::Instance<UniformShaderApply>::getInstance()
}
