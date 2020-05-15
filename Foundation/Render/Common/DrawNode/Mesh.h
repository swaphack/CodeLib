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
		*	ģ������
		*/
		void setModelDetail(const sys::ModelDetail* modelDetail);
	public:
		/**
		*	��������
		*/
		const std::map<int, sys::MeshDetail*>& getMeshes() const;
		/**
		*	����ģ������
		*/
		void addMesh(int id, sys::MeshDetail* mesh);
		/**
		*	�Ƴ�ģ������
		*/
		void removeMesh(int id);
		/**
		*	�Ƴ�����ģ������
		*/
		void removeAllMeshes();
		/**
		*	��ȡģ������
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
		// ��������
		std::map<int, sys::MeshDetail*> _meshes;

		std::map<uint32_t, VertexArrayObject*> _vertexArrayObjects;
		std::map<uint32_t, NoNamedBufferObject*> _indiceObjects;
		std::map<uint32_t, NoNamedBufferObject*> _vertexObjects;
	};
}