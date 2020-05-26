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
	*	材质
	*/
	class Materials : public sys::Object
	{
	
	public:
		Materials();
		virtual ~Materials();
	public:
		/**
		*	模型数据
		*/
		void setModelDetail(const sys::ModelDetail* modelDetail);
	public:
		/**
		*	设置模型材质
		*/
		void addMaterial(int id, sys::MaterialDetail* material);
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
		Material* getMaterial(int id);
		/**
		*	获取模型材质
		*/
		const std::map<int, Material*>& getMaterials() const;
		/**
		*	统计模型材质数量
		*/
		int getMaterialCount() const;
	public:
		/**
		*	添加纹理
		*/
		void addTexture(const std::string& name, const std::string& fullpath);
		/**
		*	添加纹理
		*/
		void addTexture(const std::string& name, const Texture* id);
		/**
		*	移除纹理
		*/
		void removeTexture(const std::string& name);
		/**
		*	移除纹理
		*/
		void removeAllTextures();
		/**
		*	获取纹理
		*/
		Texture* getTexture(const std::string& name) const;
	public:
		// 更新纹理
		void updateMatTexture();
	private:
		// 模型材质
		std::map<int, Material*> _materials;
		// 图片纹理
		std::map<std::string, Texture*> _textures;
		// 纹理路径
		std::map<std::string, std::string> _texturePaths;
	};
}