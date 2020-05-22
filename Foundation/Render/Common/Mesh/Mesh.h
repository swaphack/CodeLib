#pragma once

#include "system.h"

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
		*	网格信息
		*/
		sys::MeshDetail* getMeshDetail() const;
		/**
		*	网格信息
		*/
		VertexArrayObject* getVertexArrayObject() const;
		/**
		*	网格信息
		*/
		ElementArrayBuffer* getIndiceBuffer() const;
		/**
		*	网格信息
		*/
		ArrayBuffer* getVertexBuffer() const;
	public:
		/**
		*	使用缓存对象绘制
		*/
		void drawWithBufferObject();
		/**
		*	使用客户端数据绘制
		*/
		void drawWithClientArray();
		/**
		*	更新顶点信息
		*/
		void updateBufferData();
	private:
		sys::MeshDetail* _detail = nullptr;
		/**
		*	顶点对象
		*/
		VertexArrayObject* _vertexArrayObject = nullptr;
		/**
		*	顶点索引数据
		*/
		ElementArrayBuffer* _indiceBuffer = nullptr;
		/**
		*	顶点数据
		*/
		ArrayBuffer* _vertexBuffer = nullptr;
	};
}
