#pragma once

#include "system.h"
#include "mathlib.h"

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
		void addMaterial(int id, sys::MaterialDetail* material);
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
		Material* getMaterial(int id);
		/**
		*	��ȡģ�Ͳ���
		*/
		const std::map<int, Material*>& getMaterials() const;
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
		// ��������
		void updateMatTexture();
	private:
		// ģ�Ͳ���
		std::map<int, Material*> _materials;
		// ͼƬ����
		std::map<std::string, Texture*> _textures;
		// ����·��
		std::map<std::string, std::string> _texturePaths;
	};
}