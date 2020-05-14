#pragma once

#include "Framework/Object.h"
#include <map>
#include <string>
namespace sys
{
	class MaterialDetail;
	class MeshDetail;

	// 3dģ��
	class ModelDetail : public Object
	{
	public:
		ModelDetail();
		virtual ~ModelDetail();
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
		*	����ģ������
		*/
		void addMesh(int id, MeshDetail* mesh);
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
		MeshDetail* getMesh(int id);
		/**
		*	��ȡģ������
		*/
		const std::map<int, MeshDetail*>& getMeshes() const;
	public:
		/**
		*	��������·��
		*/
		void addTexturePath(const std::string& name, const std::string& path);
		/**
		*	�Ƴ���������·��
		*/
		void removeAllTexturePaths();
		/**
		*	��ȡ����·��
		*/
		std::string getTexturePath(const std::string& name);
		/**
		*	��ȡ����·��
		*/
		const std::map<std::string, std::string>& getTexturePaths() const;
	public:
		// ��ȡ��������·��
		std::string getTextureFullPath(const std::string& strFileName, const std::string& dir);
	protected:
		// ��������
		std::map<int, MeshDetail*> _meshes;
		// ģ�Ͳ���
		std::map<int, MaterialDetail*> _materials;
		// ����·��
		std::map<std::string, std::string> _texturePaths;
	};
}