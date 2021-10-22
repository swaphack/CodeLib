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
		/**
		*	节点
		*/
		void setNode(Node* node);
		/**
		*	节点
		*/
		Node* getNode();
	public:
		/**
		*	网格信息
		*/
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
		*	设置顶点坐标信息
		*/
		void setVertices(int len, const float* vertexes, int unitSize = 3);
		/**
		*	设置顶点
		*/
		void setVertices(const std::vector<math::Vector3>& points);
		/**
		*	设置法线坐标信息
		*/
		void setNormals(int len, const float* normals, int unitSize = 3);
		/**
		*	设置顶点
		*/
		void setNormals(const std::vector<math::Vector3>& normals);
		/**
		*	设置颜色坐标信息
		*/
		void setColors(int len, const float* colors, int unitSize = 4);
		/**
		*	设置颜色
		*/
		void setColors(const std::vector<phy::Color4F>& colors);
		/**
		*	设置纹理坐标信息
		*/
		void setUVs(int len, const float* texCoords, int unitSize = 2);
		/**
		*	设置纹理坐标
		*/
		void setUVs(const std::vector<math::Vector2>& uvs);
		/**
		*	设置三角形索引
		*/
		void setIndices(int size, const uint32_t* indices, int unitSize = 1);
		/**
		*	设置顶点顺序
		*/
		void setIndices(const std::vector<int>& indices);
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
		/**
		*	强制更新纹理数据
		*/
		void forceUpdateMeshData();
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
	public:
		/**
		*	设置模型矩阵
		*/
		void setModelMatrices(int len, const float* vertexes, int unitSize = 16);
		/**
		*	设置模型矩阵
		*/
		void setModelMatrices(int len, const math::Matrix4x4* vertexes);
		/**
		*	创建模型矩阵
		*/
		char* createModelMatrices(size_t len, int unitSize = 16);
		/**
		*	获得模型矩阵
		*/
		const sys::MeshMemoryData& getModelMatrices() const;
	public:
		/**
		*	批量绘制
		*/
		void setBatchDraw(bool bBatch);
		/**
		*	批量绘制
		*/
		bool isBatchDraw() const;
	public:
		/**
		*	相等
		*/
		bool equals(const Mesh& mesh) const;
		/**
		*	相同布局
		*/
		bool sameLayout(const Mesh& mesh) const;
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
	private:// 额外数据		
		// 模型矩阵
		sys::MeshMemoryData _modelMatrices;
		// 批量绘制
		bool _bBatchDraw = false;
		// 节点
		Node* _node = nullptr;
	};
}
