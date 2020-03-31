#pragma once

#include "system.h"

namespace render
{
	class MaterialDetail;
	class MeshDetail;

	// ģ����Դ��ʽ
	enum ModelResourceFormat
	{
		EMRF_NONE,
		EMRF_3DS,	// 3ds
		EMRF_OBJ,	// obj
		EMRF_FBX,	// fbx
	};
	// 3dģ��
	class ModelDetail
	{
	public:
		ModelDetail();
		virtual ~ModelDetail();
	public:
		// ģ����Դ��ʽ
		ModelResourceFormat getModelFormat();
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
		const std::map<int, MaterialDetail*>& geMaterials();
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
		const std::map<int, MeshDetail*>& getMeshes();
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
		// ����ģ�͸�ʽ
		void setModelFormat(ModelResourceFormat format);
	public:
		// ��������
		uint32_t createTexture(const std::string& strFileName, const std::string& dir);
		// ��������
		uint32_t createTexture(const std::string& strFullpath);
	protected:
		// ģ�Ͳ���
		std::map<int, MaterialDetail*> _materials;
		// ��������
		std::map<int, MeshDetail*> _meshes;
		// ͼƬ����
		std::map<std::string, int> _textures;
	private:
		// ģ����Դ��ʽ
		ModelResourceFormat _format = EMRF_NONE;
	};
}