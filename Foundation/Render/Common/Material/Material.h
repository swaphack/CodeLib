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

	// ͳһ����
	enum class VertexUniformType
	{
		// ͶӰ����
		PROJECT_MATRIX,
		// ��ͼ����
		VIEW_MATRIX,
		// ģ�;���
		MODEL_VIEW,
		// ��������
		AMBIENT_TEXTURE,
		// ��������
		DIFFUSE_TEXTURE,
		// �߹�����
		SPECULAR_TEXTURE,
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
		*	������Ϣ
		*/
		void setMaterialDetail(sys::MaterialDetail* detail);
		/**
		*	������Ϣ
		*/
		sys::MaterialDetail* getMaterialDetail() const;
	public:
		/**
		*	shader���ú���
		*/
		void setProgramFunc(const ShaderProgramFunc& func);
	public:
		/**
		*	���Attrib shader in�ֶ�
		*/
		void addAttrib(VertexAttribType vat, const std::string& name);
		/**
		*	���Attrib����
		*/
		std::string getAttribIndex(VertexAttribType vat) const;
		/**
		*	�Ƴ�����Attrib
		*/
		void removeAttribIndices();
	public:
		/**
		*	���Uniform shader�ֶ�
		*/
		void addUniform(VertexUniformType vut, const std::string& name);
		/**
		*	���Attrib����
		*/
		std::string getUniformIndex(VertexUniformType vut) const;
		/**
		*	�Ƴ�����Attrib
		*/
		void removeUniformIndices();
	public:
		/**
		*	ʹ�ô������ò���
		*/
		void beginApply(Materials* mats);
		/**
		*	ʹ�ô���
		*/
		void endApply(Materials* mats);
		/**
		*	ʹ��shader���ò���
		*/
		void beginApplyWithShader(Node* node, Mesh* pMesh, Materials* mats);
		/**
		*	ʹ��shader
		*/
		void endApplyWithShader(Mesh* pMesh, Materials* mats);
	protected:
		// Ӧ�ò���
		void applyMaterial();
		// ������ɫ��uniformֵ
		void startUpdateShaderUniformValue(Node* node, Materials* mats);
		// ������ɫ��attribֵ
		void startUpdateShaderVertexValue(Mesh* pMesh);
		void endUpdateShaderUniformValue(Materials* mats);
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
	};
}