#pragma once

#include "Framework/Object.h"
#include <map>
#include <string>
namespace sys
{
	class MaterialDetail;
	class MeshDetail;

	// 3d模型
	class ModelDetail : public Object
	{
	public:
		ModelDetail();
		virtual ~ModelDetail();
	public:
		/**
		*	设置模型材质
		*/
		void addMaterial(const std::string& name, MaterialDetail* material);
		/**
		*	移除模型材质
		*/
		void removeMaterial(const std::string& name);
		/**
		*	移除所有模型材质
		*/
		void removeAllMaterials();
		/**
		*	获取模型材质
		*/
		MaterialDetail* getMaterial(const std::string& name);
		/**
		*	获取模型材质
		*/
		const std::map<std::string, MaterialDetail*>& getMaterials() const;
	public:
		/**
		*	设置模型网格
		*/
		void addMesh(const std::string& name, MeshDetail* mesh);
		/**
		*	移除模型网格
		*/
		void removeMesh(const std::string& name);
		/**
		*	移除所有模型网格
		*/
		void removeAllMeshes();
		/**
		*	获取模型网格
		*/
		MeshDetail* getMesh(const std::string& name);
		/**
		*	获取模型网格
		*/
		const std::map<std::string, MeshDetail*>& getMeshes() const;
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
		std::map<std::string, MeshDetail*> _meshes;
		// 模型材质
		std::map<std::string, MaterialDetail*> _materials;
		// 纹理路径
		std::map<std::string, std::string> _texturePaths;
	};
}