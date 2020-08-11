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
	*	ͳһ��ɫ��Ӧ��
	*/
	class UniformShaderApply
	{
	public:
		UniformShaderApply();
		virtual ~UniformShaderApply();
	public:
		/**
		*	ʹ�ô������ò���
		*/
		void beginApply(Material* pMaterial, DrawTextureCache* textureCache);
		/**
		*	ʹ�ô���
		*/
		void endApply(Material* pMaterial, DrawTextureCache* textureCache);
		/**
		*	ʹ��shader���ò���
		*/
		void beginApplyWithShader(Node* node, ShaderProgram* program, Mesh* pMesh, Material* pMaterial, DrawTextureCache* textureCache);
		/**
		*	ʹ��shader
		*/
		void endApplyWithShader(ShaderProgram* program, Mesh* pMesh, Material* pMaterial, DrawTextureCache* textureCache);
	public:
		// ��ʼ������ɫ��uniformֵ
		void startUpdateShaderUniformValue(Node* node, ShaderProgram* program, Mesh* pMesh, Material* pMaterial, DrawTextureCache* textureCache);
		// ����������ɫ��attribֵ
		void startUpdateShaderVertexValue(ShaderProgram* program, Mesh* pMesh);
		// ��ʼ������ɫ��uniformֵ
		void endUpdateShaderUniformValue(ShaderProgram* program, Material* pMaterial, DrawTextureCache* textureCache);
		// ����������ɫ��attribֵ
		void endUpdateShaderVertexValue(ShaderProgram* program, Mesh* pMesh);
	protected:
		// ���¾���
		void updateMVPMatrixUniformValue(Node* node, ShaderProgram* program);
		// ���²���
		void updateMaterialUniformValue(ShaderProgram* program, Material* pMaterial, DrawTextureCache* textureCache);
		// ��������
		void updateTexturesUnifromValue(ShaderProgram* program, Material* pMaterial, DrawTextureCache* textureCache);
	public:
		// Ӧ�ù�����ɫ��
		void applyLightShader(Node* node, ShaderProgram* program);
	protected:
		// ���µ�ɫ��Դ���������
		void updateNearestLightUniformValue(Node* node, ShaderProgram* program);
		// �������й�Դ
		void updateAllLightsUniformValue(Node* node, ShaderProgram* program);
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
		*	��ʱ����
		*/
		math::Matrix4x4 _tempMatrix;
	};

#define G_UNIFORMSHADERAPPLY sys::Instance<UniformShaderApply>::getInstance()
}
