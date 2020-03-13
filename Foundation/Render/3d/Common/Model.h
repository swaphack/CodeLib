#pragma once

#include "../macros.h"

#include <map>
#include <string>

namespace render
{
	// ģ��
	class Model : public ColorNode
	{
	public:
		Model();
		virtual ~Model();
	public:
		virtual void draw();
		/**
		*	����ģ�Ͳ��� 
		*/
		void addMaterial(int id, Material* material);
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
		Material* getMatrial(int id);
		/** 
		*	����ģ������
		*/
		void addMesh(int id, Mesh* mesh);
		/**
		*	�Ƴ�ģ������
		*/
		void removeMesh(int id);
		/**
		*	�Ƴ�����ģ������
		*/
		void removeAllMeshes();
		/**
		*	��ȡģ������
		*/
		Mesh* getMesh(int id);
		/**
		*	����ģ������
		*/
		void addTexture(const std::string& name, int id);
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
		int getTexture(const std::string& name);
	protected:
		// ģ�Ͳ���
		std::map<int, Material*> _materials;
		// ��������
		std::map<int, Mesh*> _meshes;
		// ͼƬ����
		std::map<std::string, int> _textures;
	};
}