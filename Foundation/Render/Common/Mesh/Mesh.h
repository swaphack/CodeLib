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
		*	�ڵ�
		*/
		void setNode(Node* node);
		/**
		*	�ڵ�
		*/
		Node* getNode();
	public:
		/**
		*	������Ϣ
		*/
		void setMeshDetail(sys::MeshDetail* detail);
		/**
		*	������Ϣ
		*/
		sys::MeshDetail* getMeshDetail() const;
		/**
		*	���񶥵�����
		*/
		VertexArrayObject* getVertexArrayObject() const;
		/**
		*	��������
		*/
		ElementArrayBuffer* getIndiceBuffer() const;
		/**
		*	���񻺴�
		*/
		ArrayBuffer* getVertexBuffer() const;
	public:
		/**
		*	���ö���������Ϣ
		*/
		void setVertices(int len, const float* vertexes, int unitSize = 3);
		/**
		*	���ö���
		*/
		void setVertices(const std::vector<math::Vector3>& points);
		/**
		*	���÷���������Ϣ
		*/
		void setNormals(int len, const float* normals, int unitSize = 3);
		/**
		*	���ö���
		*/
		void setNormals(const std::vector<math::Vector3>& normals);
		/**
		*	������ɫ������Ϣ
		*/
		void setColors(int len, const float* colors, int unitSize = 4);
		/**
		*	������ɫ
		*/
		void setColors(const std::vector<phy::Color4F>& colors);
		/**
		*	��������������Ϣ
		*/
		void setUVs(int len, const float* texCoords, int unitSize = 2);
		/**
		*	������������
		*/
		void setUVs(const std::vector<math::Vector2>& uvs);
		/**
		*	��������������
		*/
		void setIndices(int size, const uint32_t* indices, int unitSize = 1);
		/**
		*	���ö���˳��
		*/
		void setIndices(const std::vector<int>& indices);
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
		*	���㷨��
		*/
		void setComputeNormal(bool compute);
		/**
		*	�Ƿ���㷨��
		*/
		bool isComputeNormal();
		/**
		*	��������
		*/
		void setComputeTangent(bool compute);
		/**
		*	�Ƿ��������
		*/
		bool isComputeTangent();
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
		/**
		*	��ʼ����������
		*/
		void initMeshOtherDetail();
		/**
		*	ǿ�Ƹ�����������
		*/
		void forceUpdateMeshData();
	protected:
		/**
		*	��ʼ����������
		*/
		void initDetailNormalData();
		/**
		*	��ʼ����������
		*/
		void initDetailTangentData();
		/**
		*	���������ζ��㷨��
		*/
		void calTrianglesVertexNormal(const sys::MeshMemoryData& vertices, const sys::MeshMemoryData& indices, float* normals);
		/**
		*	���������ζ��㷨��
		*/
		void calTrianglesVertexTangent(const sys::MeshMemoryData& vertices, const sys::MeshMemoryData& uvs, const sys::MeshMemoryData& indices, float* tangents);
	public:
		/**
		*	����ģ�;���
		*/
		void setModelMatrices(int len, const float* vertexes, int unitSize = 16);
		/**
		*	����ģ�;���
		*/
		void setModelMatrices(int len, const math::Matrix4x4* vertexes);
		/**
		*	����ģ�;���
		*/
		char* createModelMatrices(size_t len, int unitSize = 16);
		/**
		*	���ģ�;���
		*/
		const sys::MeshMemoryData& getModelMatrices() const;
	public:
		/**
		*	��������
		*/
		void setBatchDraw(bool bBatch);
		/**
		*	��������
		*/
		bool isBatchDraw() const;
	public:
		/**
		*	���
		*/
		bool equals(const Mesh& mesh) const;
		/**
		*	��ͬ����
		*/
		bool sameLayout(const Mesh& mesh) const;
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
		/**
		*	�Ƿ���㷨��
		*/
		bool _bComputeNormal = false;
		/**
		*	�Ƿ��������
		*/
		bool _bComputeTangent = false;
	private:// ��������		
		// ģ�;���
		sys::MeshMemoryData _modelMatrices;
		// ��������
		bool _bBatchDraw = false;
		// �ڵ�
		Node* _node = nullptr;
	};
}
