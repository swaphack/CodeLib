#pragma once

#include "system.h"
#include "mathlib.h"
#include "Common/Shader/ShaderProgramDelegate.h"

namespace sys
{
	class MeshDetail;
	class ModelDetail;
	class MaterialDetail;
}

namespace render
{
	class ShaderProgram;
	class VertexArrayObject;
	class Texture;
	class Node;
	class Material;

	/**
	*	����
	*/
	class Materials : public sys::Object
	{
	
	public:
		Materials();
		virtual ~Materials();
	public:
		/**
		*	ģ������
		*/
		void setModelDetail(const sys::ModelDetail* modelDetail);
	public:
		/**
		*	����ģ�Ͳ���
		*/
		void addMaterial(const std::string& name, sys::MaterialDetail* material);
		/**
		*	�Ƴ�ģ�Ͳ���
		*/
		void removeMaterial(const std::string& name);
		/**
		*	�Ƴ�����ģ�Ͳ���
		*/
		void removeAllMaterials();
		/**
		*	��ȡģ�Ͳ���
		*/
		Material* getMaterial(const std::string& name);
		/**
		*	��ȡģ�Ͳ���
		*/
		const std::map<std::string, Material*>& getMaterials() const;
		/**
		*	ͳ��ģ�Ͳ�������
		*/
		int getMaterialCount() const;
	public:
		/**
		*	�������
		*/
		void addTexture(const std::string& name, const std::string& fullpath);
		/**
		*	�������
		*/
		void addTexture(const std::string& name, const Texture* id);
		/**
		*	�Ƴ�����
		*/
		void removeTexture(const std::string& name);
		/**
		*	�Ƴ�����
		*/
		void removeAllTextures();
		/**
		*	��ȡ����
		*/
		Texture* getTexture(const std::string& name) const;
	public:
		/**
		*	��������
		*/
		void setMaterialTexture(const std::string& matName, const std::string& textureName);
		/**
		*	������ɫ��
		*/
		void setMaterialShaderProgram(const std::string& matName, ShaderProgram* program);
		/**
		*	������ɫ��������
		*/
		void setMaterialShaderProgramFunc(const std::string& matName, const ShaderProgramFunc& func);
	public:
		// ��������
		void updateMatTexture();
	private:
		// ģ�Ͳ���
		std::map<std::string, Material*> _materials;
		// ͼƬ����
		std::map<std::string, Texture*> _textures;
		// ����·��
		std::map<std::string, std::string> _texturePaths;
	};
}