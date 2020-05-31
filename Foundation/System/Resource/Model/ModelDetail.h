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
		void addMaterial(const std::string& name, MaterialDetail* material);
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
		MaterialDetail* getMaterial(const std::string& name);
		/**
		*	��ȡģ�Ͳ���
		*/
		const std::map<std::string, MaterialDetail*>& getMaterials() const;
	public:
		/**
		*	����ģ������
		*/
		void addMesh(const std::string& name, MeshDetail* mesh);
		/**
		*	�Ƴ�ģ������
		*/
		void removeMesh(const std::string& name);
		/**
		*	�Ƴ�����ģ������
		*/
		void removeAllMeshes();
		/**
		*	��ȡģ������
		*/
		MeshDetail* getMesh(const std::string& name);
		/**
		*	��ȡģ������
		*/
		const std::map<std::string, MeshDetail*>& getMeshes() const;
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
		std::map<std::string, MeshDetail*> _meshes;
		// ģ�Ͳ���
		std::map<std::string, MaterialDetail*> _materials;
		// ����·��
		std::map<std::string, std::string> _texturePaths;
	};
}