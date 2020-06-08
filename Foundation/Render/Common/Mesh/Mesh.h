#pragma once

#include "system.h"
#include "Graphic/GLAPI/macros.h"
namespace sys
{
	class MeshDetail;
}

namespace render
{
	class VertexArrayObject;
	class ElementArrayBuffer;
	class ArrayBuffer;
	class Material;
	class Node;

	class Mesh : public sys::Object
	{
	public:
		Mesh();
		virtual ~Mesh();
	public:
		void setMeshDetail(sys::MeshDetail* detail);
		/**
		*	������Ϣ
		*/
		sys::MeshDetail* getMeshDetail() const;
		/**
		*	������Ϣ
		*/
		VertexArrayObject* getVertexArrayObject() const;
		/**
		*	������Ϣ
		*/
		ElementArrayBuffer* getIndiceBuffer() const;
		/**
		*	������Ϣ
		*/
		ArrayBuffer* getVertexBuffer() const;
	public:
		/**
		*	����ͼ�η�ʽ
		*/
		void setDrawMode(DrawMode mode);
		/**
		*	����ͼ�η�ʽ
		*/
		DrawMode getDrawMode() const;
	public:
		/**
		*	ʹ�û���������
		*/
		void drawWithBufferObject();
		/**
		*	ʹ�ÿͻ������ݻ���
		*/
		void drawWithClientArray();
		/**
		*	���¶�����Ϣ
		*/
		void updateBufferData();
	private:
		sys::MeshDetail* _detail = nullptr;
		/**
		*	�������
		*/
		VertexArrayObject* _vertexArrayObject = nullptr;
		/**
		*	������������
		*/
		ElementArrayBuffer* _indiceBuffer = nullptr;
		/**
		*	��������
		*/
		ArrayBuffer* _vertexBuffer = nullptr;
		/**
		*	����ͼ�η�ʽ
		*/
		DrawMode _drawMode = DrawMode::TRIANGLES;
	};
}
