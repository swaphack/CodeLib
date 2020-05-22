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
		const std::map<int, Mesh*>& getMeshes() const;
		/**
		*	设置模型网格
		*/
		void addMesh(int id, sys::MeshDetail* mesh);
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
	public:
		/**
		*	使用缓存对象绘制
		*/
		void drawWithBufferObject(Node* node, Materials* mats);
		/**
		*	使用客户端数组绘制
		*/
		void drawWithClientArray(Node* node, Materials* mats);
		/**
		*	更新顶点信息
		*/
		void updateBufferData();
	private:
		// 纹理网格
		std::map<int, Mesh*> _meshes;
	};
}