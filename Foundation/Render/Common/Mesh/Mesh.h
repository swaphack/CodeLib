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
		*	网格信息
		*/
		sys::MeshDetail* getMeshDetail() const;
		/**
		*	网格顶点数据
		*/
		VertexArrayObject* getVertexArrayObject() const;
		/**
		*	网格索引
		*/
		ElementArrayBuffer* getIndiceBuffer() const;
		/**
		*	网格缓存
		*/
		ArrayBuffer* getVertexBuffer() const;
	public:
		/**
		*	绘制图形方式
		*/
		void setDrawMode(DrawMode mode);
		/**
		*	绘制图形方式
		*/
		DrawMode getDrawMode() const;
	public:
		/**
		*	计算法线
		*/
		void setComputeNormal(bool compute);
		/**
		*	是否计算法线
		*/
		bool isComputeNormal();
		/**
		*	计算切线
		*/
		void setComputeTangent(bool compute);
		/**
		*	是否计算切线
		*/
		bool isComputeTangent();
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
		/**
		*	初始化其他数据
		*/
		void initMeshOtherDetail();
	protected:
		/**
		*	初始化法线数据
		*/
		void initDetailNormalData();
		/**
		*	初始化切线数据
		*/
		void initDetailTangentData();
		/**
		*	计算三角形顶点法线
		*/
		void calTrianglesVertexNormal(const sys::MeshMemoryData& vertices, const sys::MeshMemoryData& indices, float* normals);
		/**
		*	计算三角形顶点法线
		*/
		void calTrianglesVertexTangent(const sys::MeshMemoryData& vertices, const sys::MeshMemoryData& uvs, const sys::MeshMemoryData& indices, float* tangents);
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
		/**
		*	绘制图形方式
		*/
		DrawMode _drawMode = DrawMode::TRIANGLES;
		/**
		*	是否计算法线
		*/
		bool _bComputeNormal = false;
		/**
		*	是否计算切线
		*/
		bool _bComputeTangent = false;
	};
}
