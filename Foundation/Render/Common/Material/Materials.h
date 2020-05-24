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
	class Texture2D;
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
	
	public:
		/**
		*	����ģ������
		*/
		void addTexture(const std::string& name, const Texture2D* id);
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
		Texture2D* getTexture(const std::string& name) const;

		// ��������
		Texture2D* createTexture(const std::string& strFullpath);
		// ��������
		void updateMatTexture();
	private:
		// ģ�Ͳ���
		std::map<int, Material*> _materials;
		// ͼƬ����
		std::map<std::string, Texture2D*> _textures;
		// ����·��
		std::map<std::string, std::string> _texturePaths;
	};
}