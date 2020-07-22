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
		void beginApply(DrawTextureCache* textureCache);
		/**
		*	ʹ�ô���
		*/
		void endApply(DrawTextureCache* textureCache);
		/**
		*	ʹ��shader���ò���
		*/
		void beginApplyWithShader(Node* node, Mesh* pMesh, DrawTextureCache* textureCache);
		/**
		*	ʹ��shader
		*/
		void endApplyWithShader(Mesh* pMesh, DrawTextureCache* textureCache);
	protected:
		// Ӧ�ò���
		void applyMaterial();
		// ������ɫ��uniformֵ
		void startUpdateShaderUniformValue(Node* node, DrawTextureCache* textureCache);
		// ������ɫ��attribֵ
		void startUpdateShaderVertexValue(Mesh* pMesh);

		void endUpdateShaderUniformValue(DrawTextureCache* textureCache);
		void endUpdateShaderVertexValue(Mesh* pMesh);
	protected:
		// ���¾���
		void updateMVPMatrixUniformValue(Node* node);
		// ���µ�ɫ��Դ���������
		void updateNearestLightUniformValue(Node* node);
		// �������й�Դ
		void updateAllLightsUniformValue(Node* node);
		// ���²���
		void updateMaterialUniformValue(DrawTextureCache* textureCache);
		// ��������
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