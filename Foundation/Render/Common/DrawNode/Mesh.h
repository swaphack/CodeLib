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
	class NoNamedBufferObject;
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
		void drawWithBufferObject(Node* node, Material* mat);

		void drawWithClientArray(Node* node, Material* mat);

		void initBufferData();

		void updateVerticeData();

		void removeAllBufferObjects();
	protected:
	private:
		// 纹理网格
		std::map<int, sys::MeshDetail*> _meshes;

		std::map<uint32_t, VertexArrayObject*> _vertexArrayObjects;
		std::map<uint32_t, NoNamedBufferObject*> _indiceObjects;
		std::map<uint32_t, NoNamedBufferObject*> _vertexObjects;
	};
}