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
		const std::map<int, Mesh*>& getMeshes() const;
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
		Mesh* getMesh(int id);
	public:
		/**
		*	ʹ�û���������
		*/
		void drawWithBufferObject(Node* node, Materials* mats);
		/**
		*	ʹ�ÿͻ����������
		*/
		void drawWithClientArray(Node* node, Materials* mats);
		/**
		*	���¶�����Ϣ
		*/
		void updateBufferData();
	private:
		// ��������
		std::map<int, Mesh*> _meshes;
	};
}