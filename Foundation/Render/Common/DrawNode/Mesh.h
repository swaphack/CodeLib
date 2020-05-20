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
	class Material;
	class Node;

	class Mesh : public sys::Object
	{
	public:
		Mesh();
		virtual ~Mesh();
	public:
		/**
		*	模型数据
		*/
		void setModelDetail(const sys::ModelDetail* modelDetail);
	public:
		/**
		*	网格数据
		*/
		const std::map<int, sys::MeshDetail*>& getMeshes() const;
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
		sys::MeshDetail* getMesh(int id);
	public:
		/**
		*	使用缓存对象绘制
		*/
		void drawWithBufferObject(Node* node, Material* mat);
		/**
		*	使用客户端数组绘制
		*/
		void drawWithClientArray(Node* node, Material* mat);
		/**
		*	初始化
		*/
		void initBufferData();
		/**
		*	更新顶点信息
		*/
		void updateBufferData();
		/**
		*	移除所有缓存对象
		*/
		void removeAllBufferObjects();
	private:
		// 纹理网格
		std::map<int, sys::MeshDetail*> _meshes;

		std::map<uint32_t, VertexArrayObject*> _vertexArrayObjects;
		std::map<uint32_t, ElementArrayBuffer*> _indiceObjects;
		std::map<uint32_t, ArrayBuffer*> _vertexObjects;
	};
}