#pragma once

#include "system.h"

namespace render
{
	class Texture2D;
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
	class ModelDetail : public sys::Object
	{
	public:
		ModelDetail();
		virtual ~ModelDetail();
	public:
		// ģ����Դ��ʽ
		ModelResourceFormat getModelFormat();
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
		const std::map<int, MaterialDetail*>& geMaterials();
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
		const std::map<int, MeshDetail*>& getMeshes();
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
		int getTexture(const std::string& name);
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
		const std::map<std::string, std::string>& getTexturePaths();
	protected:
		// ����ģ�͸�ʽ
		void setModelFormat(ModelResourceFormat format);
	public:
		// ��������
		Texture2D* createTexture(const std::string& strFileName, const std::string& dir);
		// ��������
		Texture2D* createTexture(const std::string& strFullpath);
		// ��ȡ��������·��
		std::string getTextureFullPath(const std::string& strFileName, const std::string& dir);
	protected:
		// ģ�Ͳ���
		std::map<int, MaterialDetail*> _materials;
		// ��������
		std::map<int, MeshDetail*> _meshes;
		// ͼƬ����
		std::map<std::string, Texture2D*> _textures;
		// ����·��
		std::map<std::string, std::string> _texturePaths;
	private:
		// ģ����Դ��ʽ
		ModelResourceFormat _format = EMRF_NONE;
	};
}