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
		*	ģ������
		*/
		void setModelDetail(const sys::ModelDetail* modelDetail);
	public:
		/**
		*	��������
		*/
		const std::map<std::string, Mesh*>& getMeshes() const;
		/**
		*	����ģ������
		*/
		void addMesh(const std::string& name, sys::MeshDetail* mesh);
		/**
		*	�Ƴ�ģ������
		*/
		void removeMesh(const std::string& name);
		/**
		*	�Ƴ�����ģ������
		*/
		void removeAllMeshes();
		/**
		*	��ȡģ������
		*/
		Mesh* getMesh(const std::string& name);
	public:
		/**
		*	ʹ�û���������
		*/
		void drawNodeWithMaterials(Node* node, Materials* mats);
		/**
		*	���¶�����Ϣ
		*/
		void updateBufferData();
	private:
		// ��������
		std::map<std::string, Mesh*> _meshes;
	};
}