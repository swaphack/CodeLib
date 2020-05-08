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
		*	����ģ�Ͳ���
		*/
		void addMaterial(int id, MaterialDetail* material);
		/**
		*	�Ƴ�ģ�Ͳ���
		*/
		void removeMaterial(int id);
		/**
		*	�Ƴ�����ģ�Ͳ���
		*/
		void removeAllMaterials();
		/**
		*	��ȡģ�Ͳ���
		*/
		MaterialDetail* getMaterial(int id);
		/**
		*	��ȡģ�Ͳ���
		*/
		const std::map<int, MaterialDetail*>& getMaterials() const;
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
		*	���Attrib shader in�ֶ�
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
		*	����ģ������
		*/
		void addTexture(const std::string& name, Texture2D* id);
		/**
		*	�Ƴ�ģ������
		*/
		void removeTexture(const std::string& name);
		/**
		*	�Ƴ�����ģ������
		*/
		void removeAllTextures();
		/**
		*	��ȡģ������
		*/
		int getTexture(const std::string& name) const;

		// ��������
		Texture2D* createTexture(const std::string& strFullpath);
	public:
		// ������ɫ��uniformֵ
		void startUpdateShaderUniformValue(const math::Matrix44& projMat, const math::Matrix44& viewMat, const math::Matrix44& modelMat);
		void endUpdateShaderUniformValue();

		// ������ɫ��inֵ
		void startUpdateShaderVertexValue(VertexArrayObject* data);
		void endUpdateShaderVertexValue(VertexArrayObject* data);

		// Ӧ�ò���
		void applyMat(uint32_t nMatID) const;
		// ��������
		void updateMatTexture();
		// �Ƴ����л������
		void removeAllBufferObjects();
	private:
		// ģ�Ͳ���
		std::map<int, MaterialDetail*> _materials;
		// ͼƬ����
		std::map<std::string, Texture2D*> _textures;
		// ����·��
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