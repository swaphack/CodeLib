#pragma once

#include "system.h"

namespace sys
{
	class ModelDetail;
	class MeshDetail;
}

namespace render
{
	class VertexArrayObject;
	class ArrayBuffer;
	class ElementArrayBuffer;
	class Materials;
	class Node;
	class Mesh;

	class Meshes : public sys::Object
	{
	public:
		Meshes();
		virtual ~Meshes();
	public:
		/**
		*	模型数据
		*/
		void setModelDetail(const sys::ModelDetail* modelDetail);
	public:
		/**
		*	网格数据
		*/
		const std::map<std::string, Mesh*>& getMeshes() const;
		/**
		*	设置模型网格
		*/
		void addMesh(const std::string& name, sys::MeshDetail* mesh);
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
		Mesh* getMesh(const std::string& name);
	public:
		/**
		*	使用缓存对象绘制
		*/
		void drawNodeWithMaterials(Node* node, Materials* mats);
		/**
		*	更新顶点信息
		*/
		void updateBufferData();
	private:
		// 纹理网格
		std::map<std::string, Mesh*> _meshes;
	};
}