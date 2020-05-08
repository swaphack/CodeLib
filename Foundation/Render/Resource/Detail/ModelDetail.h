#pragma once

#include "system.h"

namespace render
{
	class Texture2D;
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
	class ModelDetail : public sys::Object
	{
	public:
		ModelDetail();
		virtual ~ModelDetail();
	public:
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
		const std::map<int, MaterialDetail*>& getMaterials() const;
	public:
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
		const std::map<int, MeshDetail*>& getMeshes() const;
	public:
		/**
		*	设置纹理路径
		*/
		void addTexturePath(const std::string& name, const std::string& path);
		/**
		*	移除所有纹理路径
		*/
		void removeAllTexturePaths();
		/**
		*	获取纹理路径
		*/
		std::string getTexturePath(const std::string& name);
		/**
		*	获取纹理路径
		*/
		const std::map<std::string, std::string>& getTexturePaths() const;
	public:
		// 获取纹理完整路径
		std::string getTextureFullPath(const std::string& strFileName, const std::string& dir);
	protected:
		// 纹理网格
		std::map<int, MeshDetail*> _meshes;
		// 模型材质
		std::map<int, MaterialDetail*> _materials;
		// 纹理路径
		std::map<std::string, std::string> _texturePaths;
	};
}