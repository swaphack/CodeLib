#pragma once

#include "system.h"

namespace render
{
	class MaterialDetail;
	class MeshDetail;

	// 模型资源格式
	enum ModelResourceFormat
	{
		EMRF_NONE,
		EMRF_3DS,	// 3ds
		EMRF_OBJ,	// obj
		EMRF_FBX,	// fbx
	};
	// 3d模型
	class ModelDetail
	{
	public:
		ModelDetail();
		virtual ~ModelDetail();
	public:
		// 模型资源格式
		ModelResourceFormat getModelFormat();
		/**
		*	设置模型材质
		*/
		void addMaterial(int id, MaterialDetail* material);
		/**
		*	移除模型材质
		*/
		void removeMaterial(int id);
		/**
		*	移除所有模型材质
		*/
		void removeAllMaterials();
		/**
		*	获取模型材质
		*/
		MaterialDetail* getMaterial(int id);
		/**
		*	获取模型材质
		*/
		const std::map<int, MaterialDetail*>& geMaterials();
		/**
		*	设置模型网格
		*/
		void addMesh(int id, MeshDetail* mesh);
		/**
		*	移除模型网格
		*/
		void removeMesh(int id);
		/**
		*	移除所有模型网格
		*/
		void removeAllMeshes();
		/**
		*	获取模型网格
		*/
		MeshDetail* getMesh(int id);
		/**
		*	获取模型网格
		*/
		const std::map<int, MeshDetail*>& getMeshes();
		/**
		*	设置模型网格
		*/
		void addTexture(const std::string& name, int id);
		/**
		*	移除模型网格
		*/
		void removeTexture(const std::string& name);
		/**
		*	移除所有模型网格
		*/
		void removeAllTextures();
		/**
		*	获取模型网格
		*/
		int getTexture(const std::string& name);
	protected:
		// 设置模型格式
		void setModelFormat(ModelResourceFormat format);
	public:
		// 创建纹理
		uint32_t createTexture(const std::string& strFileName, const std::string& dir);
		// 创建纹理
		uint32_t createTexture(const std::string& strFullpath);
	protected:
		// 模型材质
		std::map<int, MaterialDetail*> _materials;
		// 纹理网格
		std::map<int, MeshDetail*> _meshes;
		// 图片纹理
		std::map<std::string, int> _textures;
	private:
		// 模型资源格式
		ModelResourceFormat _format = EMRF_NONE;
	};
}