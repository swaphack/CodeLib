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

	// ͳһ����
	enum class UniformType
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
		// ��������
		LIGHT_AMBIENT,
		// �������
		LIGHT_DIFFUSE,
		// �߹����
		LIGHT_SPECULAR,
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
		void addVertexData(VertexDataType vat, const std::string& name);
		/**
		*	���Attrib����
		*/
		std::string getVertexName(VertexDataType vat) const;
		/**
		*	�Ƴ�����Attrib
		*/
		void removeVertexDatas();
	public:
		/**
		*	���Uniform shader�ֶ�
		*/
		void addUniform(UniformType vut, const std::string& name);
		/**
		*	���Attrib����
		*/
		std::string getUniformName(UniformType vut) const;
		/**
		*	�Ƴ�����Attrib
		*/
		void removeUniformDatas();
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
		*	vertex
		*/
		std::map<VertexDataType, std::string> _vertexAttribIndices;
		/**
		*	Uniform
		*/
		std::map<UniformType, std::string> _vertexUniformIndices;
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