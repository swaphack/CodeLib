#pragma once

#include "system.h"

namespace render
{
	class ModelDetail;
	class VertexArrayObject;
	class NoNamedBufferObject;
	class MeshDetail;
	class Material;

	class Mesh : public sys::Object
	{
	public:
		Mesh();
		virtual ~Mesh();
	public:
		/**
		*	模型数据
		*/
		void setModelDetail(const ModelDetail* modelDetail);
	public:
		/**
		*	网格数据
		*/
		const std::map<int, MeshDetail*>& getMeshes() const;
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
	public:
		void draw(Material* mat);

		void updateBufferData();

		void removeAllBufferObjects();
	protected:
	private:
		// 纹理网格
		std::map<int, MeshDetail*> _meshes;

		std::map<uint32_t, VertexArrayObject*> _vertexArrayObjects;
		std::map<uint32_t, NoNamedBufferObject*> _indiceObjects;
		std::map<uint32_t, NoNamedBufferObject*> _vertexObjects;
	};
}