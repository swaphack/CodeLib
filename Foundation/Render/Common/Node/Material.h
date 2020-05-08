#pragma once

#include "system.h"
#include "mathlib.h"

namespace render
{
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

	enum class VertexUniformType
	{
		PROJECT_MATRIX,
		VIEW_MATRIX,
		MODEL_VIEW,
	};

	class ModelDetail;
	class ShaderProgram;
	class VertexArrayObject;
	class NoNamedBufferObject;
	class Texture2D;
	class MaterialDetail;
	/**
	*	材质
	*/
	class Material : public sys::Object
	{
	public:
		Material();
		virtual ~Material();
	public:
		/**
		*	模型数据
		*/
		void setModelDetail(const ModelDetail* modelDetail);
		/**
		*	shader
		*/
		void setShaderProgram(ShaderProgram* shaderProgram);
		/**
		*	shader
		*/
		ShaderProgram* getShaderProgram();
	public:
		/**
		*	设置模型材质
		*/
		void addMaterial(int id, MaterialDetail* material);
		/**
		*	移除模型材质
		*/
		void removeMaterial(int id);
		/**
		*	移除所有模型材质
		*/
		void removeAllMaterials();
		/**
		*	获取模型材质
		*/
		MaterialDetail* getMaterial(int id);
		/**
		*	获取模型材质
		*/
		const std::map<int, MaterialDetail*>& getMaterials() const;
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
		*	添加Attrib shader in字段
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
		/**
		*	设置模型网格
		*/
		void addTexture(const std::string& name, Texture2D* id);
		/**
		*	移除模型网格
		*/
		void removeTexture(const std::string& name);
		/**
		*	移除所有模型网格
		*/
		void removeAllTextures();
		/**
		*	获取模型网格
		*/
		int getTexture(const std::string& name) const;

		// 创建纹理
		Texture2D* createTexture(const std::string& strFullpath);
	public:
		// 更新着色器uniform值
		void startUpdateShaderUniformValue(const math::Matrix44& projMat, const math::Matrix44& viewMat, const math::Matrix44& modelMat);
		void endUpdateShaderUniformValue();

		// 更新着色器in值
		void startUpdateShaderVertexValue(VertexArrayObject* data);
		void endUpdateShaderVertexValue(VertexArrayObject* data);

		// 应用材质
		void applyMat(uint32_t nMatID) const;
		// 更新纹理
		void updateMatTexture();
		// 移除所有缓存对象
		void removeAllBufferObjects();
	private:
		// 模型材质
		std::map<int, MaterialDetail*> _materials;
		// 图片纹理
		std::map<std::string, Texture2D*> _textures;
		// 纹理路径
		std::map<std::string, std::string> _texturePaths;
		/**
		*	shader
		*/
		ShaderProgram* _shaderProgram = nullptr;
		/**
		*	Attrib
		*/
		std::map<VertexAttribType, std::string> _vertexAttribIndices;
		/**
		*	Uniform
		*/
		std::map<VertexUniformType, std::string> _vertexUniformIndices;
	};
}