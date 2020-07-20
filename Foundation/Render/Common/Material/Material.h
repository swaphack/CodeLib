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

	enum class VertexDataType
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
	enum class UniformType
	{
		// 投影矩阵
		PROJECT_MATRIX,
		// 视图矩阵
		VIEW_MATRIX,
		// 模型矩阵
		MODEL_VIEW,

		// 纹理
		TEXTURE0,
		// 纹理
		TEXTURE1,
		// 纹理
		TEXTURE2,
		// 纹理
		TEXTURE3,
		// 纹理
		TEXTURE4,
		// 纹理
		TEXTURE5,
		// 纹理
		TEXTURE6,
		// 纹理
		TEXTURE7,
		// 纹理
		TEXTURE8,
		// 纹理
		TEXTURE9,
		// 纹理
		TEXTURE10,
		// 纹理
		TEXTURE11,
		// 纹理
		TEXTURE12,
		// 纹理
		TEXTURE13,
		// 纹理
		TEXTURE14,
		// 纹理
		TEXTURE15,
		// 纹理
		TEXTURE16,
		// 纹理
		TEXTURE17,
		// 纹理
		TEXTURE18,
		// 纹理
		TEXTURE19,
		// 纹理
		TEXTURE20,
		// 纹理
		TEXTURE21,
		// 纹理
		TEXTURE22,
		// 纹理
		TEXTURE23,
		// 纹理
		TEXTURE24,
		// 纹理
		TEXTURE25,
		// 纹理
		TEXTURE26,
		// 纹理
		TEXTURE27,
		// 纹理
		TEXTURE28,
		// 纹理
		TEXTURE29,
		// 纹理
		TEXTURE30,
		// 纹理
		TEXTURE31,

		// 材质环境参数
		MATERIAL_COLOR_AMBIENT,
		// 材质漫射参数
		MATERIAL_COLOR_DIFFUSE,
		// 材质高光参数
		MATERIAL_COLOR_SPECULAR,
		// 材质环境参数
		MATERIAL_TEXTURE_AMBIENT,
		// 材质漫射参数
		MATERIAL_TEXTURE_DIFFUSE,
		// 材质高光参数
		MATERIAL_TEXTURE_SPECULAR,
		// 材质亮度参数
		MATERIAL_SHININESS,

		// 光源颜色参数
		LIGHT_COLOR,
		// 光源颜色参数
		LIGHT_AMBIENT,
		// 光源颜色参数
		LIGHT_DIFFUSE,
		// 光源颜色参数
		LIGHT_SPECULAR,
		// 光源位置参数
		LIGHT_POSITION,

		// 光源颜色参数
		LIGHT_COLORS,
		// 光源颜色参数
		LIGHT_AMBIENTS,
		// 光源颜色参数
		LIGHT_DIFFUSES,
		// 光源颜色参数
		LIGHT_SPECULARS,
		// 光源位置参数
		LIGHT_POSITIONS,

		// 摄像机位置
		VIEW_POSITION,
	};

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
		void updateAllLightsUniformValue();
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