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
		void setModelDetail(ModelDetail* modelDetail);
		/**
		*	模型数据
		*/
		ModelDetail* getModelDetail();
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
		*	添加Attrib shader in字段
		*/
		void addVertexAttrib(VertexAttribType vat, uint32_t index);
		/**
		*	添加Attrib索引
		*/
		int32_t getVertexAttribIndex(VertexAttribType vat);
		/**
		*	移除所有Attrib
		*/
		void removeVertexAttribIndices();
	public:
		/**
		*	添加Attrib shader in字段
		*/
		void addVertexUniform(VertexAttribType vat, uint32_t index);
		/**
		*	添加Attrib索引
		*/
		int32_t getVertexUniformIndex(VertexAttribType vat);
		/**
		*	移除所有Attrib
		*/
		void removeVertexUniformIndices();
	public:
		void draw(const math::Matrix44& projMat, const math::Matrix44& viewMat, const math::Matrix44& modelMat);

		// 应用材质
		void applyMatToMesh(uint32_t nMatID);
		// 更新纹理
		void updateMatTexture();
		// 更新缓存数据
		void updateBufferData();
		// 移除所有缓存对象
		void removeAllBufferObjects();
	private:
		/**
		*	模型数据
		*/
		ModelDetail* _modelDetail = nullptr;
		/**
		*	shader
		*/
		ShaderProgram* _shaderProgram = nullptr;
		/**
		*	Attrib
		*/
		std::map<VertexAttribType, uint32_t> _vertexAttribIndices;
		/**
		*	Uniform
		*/
		std::map<VertexUniformType, uint32_t> _vertexUniformIndices;

		std::map<uint32_t, VertexArrayObject*> _vertexArrayObjects;
		std::map<uint32_t, NoNamedBufferObject*> _indiceObjects;
		std::map<uint32_t, NoNamedBufferObject*> _vertexObjects;
	};
}