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
	};
}
