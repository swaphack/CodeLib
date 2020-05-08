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
	*	����
	*/
	class Material : public sys::Object
	{
	public:
		Material();
		virtual ~Material();
	public:
		/**
		*	ģ������
		*/
		void setModelDetail(ModelDetail* modelDetail);
		/**
		*	ģ������
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
		*	���Attrib shader in�ֶ�
		*/
		void addVertexAttrib(VertexAttribType vat, uint32_t index);
		/**
		*	���Attrib����
		*/
		int32_t getVertexAttribIndex(VertexAttribType vat);
		/**
		*	�Ƴ�����Attrib
		*/
		void removeVertexAttribIndices();
	public:
		/**
		*	���Attrib shader in�ֶ�
		*/
		void addVertexUniform(VertexAttribType vat, uint32_t index);
		/**
		*	���Attrib����
		*/
		int32_t getVertexUniformIndex(VertexAttribType vat);
		/**
		*	�Ƴ�����Attrib
		*/
		void removeVertexUniformIndices();
	public:
		void draw(const math::Matrix44& projMat, const math::Matrix44& viewMat, const math::Matrix44& modelMat);

		// Ӧ�ò���
		void applyMatToMesh(uint32_t nMatID);
		// ��������
		void updateMatTexture();
		// ���»�������
		void updateBufferData();
		// �Ƴ����л������
		void removeAllBufferObjects();
	private:
		/**
		*	ģ������
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