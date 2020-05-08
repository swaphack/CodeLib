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
		*	ģ������
		*/
		void setModelDetail(const ModelDetail* modelDetail);
	public:
		/**
		*	��������
		*/
		const std::map<int, MeshDetail*>& getMeshes() const;
		/**
		*	����ģ������
		*/
		void addMesh(int id, MeshDetail* mesh);
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
		MeshDetail* getMesh(int id);
	public:
		void draw(Material* mat);

		void updateBufferData();

		void removeAllBufferObjects();
	protected:
	private:
		// ��������
		std::map<int, MeshDetail*> _meshes;

		std::map<uint32_t, VertexArrayObject*> _vertexArrayObjects;
		std::map<uint32_t, NoNamedBufferObject*> _indiceObjects;
		std::map<uint32_t, NoNamedBufferObject*> _vertexObjects;
	};
}