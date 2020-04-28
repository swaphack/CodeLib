#pragma once

#include "system.h"
#include "mathlib.h"
#include "Common/struct/pointer_common.h"

#include <map>

namespace render
{
	class MeshDetail : public sys::Object
	{
	public:
		MeshDetail();
		virtual ~MeshDetail();
	public:
		const std::string& getMeshName();

		void setMeshName(const std::string& name);
		/**
		*	������
		*/
		int getVerticesCount();
		/**
		*	����������Ϣ
		*/
		const T_Vertex& getVertices();
		/**
		*	���ö���������Ϣ
		*/
		void setVertices(int size, float* vertexes, int unitSize = 3);
		/**
		*	����������Ϣ
		*/
		const T_Vertex& getNormals();
		/**
		*	���÷���������Ϣ
		*/
		void setNormals(int size, float* normals, int unitSize = 3);
		/**
		*	��ɫ������Ϣ
		*/
		const T_Vertex& getColors();
		/**
		*	������ɫ������Ϣ
		*/
		void setColors(int size, float* colors, int unitSize = 3);
		/**
		*	����������Ϣ
		*/
		const T_Vertex& getUVs();
		/**
		*	��������������Ϣ
		*/
		void setUVs(int size, float* texCoords, int unitSize = 2);
		/**
		*	���ò���
		*/
		void setMaterial(int mat);
		/**
		*	��ȡ����
		*/
		int getMaterial();
		/**
		*	��������������
		*/
		void setIndices(int size, uint32_t* indices);
		/**
		*	��ȡ����������
		*/
		const T_Indice& getIndices();
		/**
		*	��ȡ�任����
		*/
		const math::Matrix44& getMatrix();
		/**
		*	���ñ任����
		*/
		void setMatrix(const math::Matrix44& mat);
	private:
		std::string _meshName;
		// ����
		int _material = 0;
		// ��������
		T_Indice _indices;
		// �������� (x,y,z)
		T_Vertex _vertices;
		// �������� (x,y,z)
		T_Vertex _normals;
		// ��ɫ (r,g,b,a)
		T_Vertex _colors;
		// �������� (x,y,z)
		T_Vertex _uvs;
		// �任����
		math::Matrix44 _matrix;
	};
}