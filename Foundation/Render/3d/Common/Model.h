#pragma once

#include "../macros.h"

#include <map>
#include <string>

namespace render
{
	// 模型
	class Model : public ColorNode
	{
	public:
		Model();
		virtual ~Model();
	public:
		virtual void draw();
		/**
		*	设置模型材质 
		*/
		void addMaterial(int id, Material* material);
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
		Material* getMatrial(int id);
		/** 
		*	设置模型网格
		*/
		void addMesh(int id, Mesh* mesh);
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
		Mesh* getMesh(int id);
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
		// 模型材质
		std::map<int, Material*> _materials;
		// 纹理网格
		std::map<int, Mesh*> _meshes;
		// 图片纹理
		std::map<std::string, int> _textures;
	};
}