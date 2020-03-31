#pragma once

#include "system.h"

#include "Common/struct/pointer_common.h"
#include <map>

namespace render
{
	class FaceDetail; 

	class MeshDetail : public sys::Object
	{
	public:
		MeshDetail();
		virtual ~MeshDetail();
	public:
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
		*	�����
		*/
		void addFace(int id, FaceDetail* face);
		/**
		*	�Ƴ���
		*/
		void removeFace(int id);
		/**
		*	��ȡ��
		*/
		FaceDetail* getFace(int id);
		/**
		*	�Ƴ�������
		*/
		void removeAllFaces();
		/**
		*	��ȡ������
		*/
		const std::map<int, FaceDetail*>& getFaces();
	private:
		// ��
		std::map<int, FaceDetail*> _faces;
		// �������� (x,y,z)
		T_Vertex _vertices;
		// �������� (x,y,z)
		T_Vertex _normals;
		// ��ɫ (r,g,b,a)
		T_Vertex _colors;
		// �������� (x,y,z)
		T_Vertex _uvs;
	};
}