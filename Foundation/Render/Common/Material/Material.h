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
		// ����
		TEXTURE0,
		// ����
		TEXTURE1,
		// ����
		TEXTURE2,
		// ����
		TEXTURE3,
		// ����
		TEXTURE4,
		// ����
		TEXTURE5,
		// ����
		TEXTURE6,
		// ����
		TEXTURE7,
		// ����
		TEXTURE8,
		// ����
		TEXTURE9,
		// ����
		TEXTURE10,
		// ����
		TEXTURE11,
		// ����
		TEXTURE12,
		// ����
		TEXTURE13,
		// ����
		TEXTURE14,
		// ����
		TEXTURE15,
		// ����
		TEXTURE16,
		// ����
		TEXTURE17,
		// ����
		TEXTURE18,
		// ����
		TEXTURE19,
		// ����
		TEXTURE20,
		// ����
		TEXTURE21,
		// ����
		TEXTURE22,
		// ����
		TEXTURE23,
		// ����
		TEXTURE24,
		// ����
		TEXTURE25,
		// ����
		TEXTURE26,
		// ����
		TEXTURE27,
		// ����
		TEXTURE28,
		// ����
		TEXTURE29,
		// ����
		TEXTURE30,
		// ����
		TEXTURE31,
		// ���ʻ�������
		MATERIAL_COLOR_AMBIENT,
		// �����������
		MATERIAL_COLOR_DIFFUSE,
		// ���ʸ߹����
		MATERIAL_COLOR_SPECULAR,
		// ���ʻ�������
		MATERIAL_TEXTURE_AMBIENT,
		// �����������
		MATERIAL_TEXTURE_DIFFUSE,
		// ���ʸ߹����
		MATERIAL_TEXTURE_SPECULAR,
		// �������Ȳ���
		MATERIAL_SHININESS,
		// ��Դ��ɫ����
		LIGHT_COLOR,
		// ��Դ��ɫ����
		LIGHT_AMBIENT,
		// ��Դ��ɫ����
		LIGHT_DIFFUSE,
		// ��Դ��ɫ����
		LIGHT_SPECULAR,
		// ��Դλ�ò���
		LIGHT_POSITION,
		// �����λ��
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