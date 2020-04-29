#pragma once

#include "system.h"
#include "mathlib.h"

#include <map>

namespace render
{
	class MeshMemoryData : public sys::MemoryData
	{
	public:
		void setTypeSize(uint32_t size) { _typeSize = size; }
		uint32_t getTypeSize() { return _typeSize; }
	protected:
	private:
		uint32_t _typeSize = 0;
	};
	class MeshDetail : public sys::Object
	{
	public:
		MeshDetail();
		virtual ~MeshDetail();
	public:
		const std::string& getMeshName();

		void setMeshName(const std::string& name);
		/**
		*	����������Ϣ
		*/
		const MeshMemoryData& getVertices();
		/**
		*	���ö���������Ϣ
		*/
		void setVertices(int size, float* vertexes, int unitSize = 3);
		/**
		*	����������Ϣ
		*/
		const MeshMemoryData& getNormals();
		/**
		*	���÷���������Ϣ
		*/
		void setNormals(int size, float* normals, int unitSize = 3);
		/**
		*	��ɫ������Ϣ
		*/
		const MeshMemoryData& getColors();
		/**
		*	������ɫ������Ϣ
		*/
		void setColors(int size, float* colors, int unitSize = 3);
		/**
		*	����������Ϣ
		*/
		const MeshMemoryData& getUVs();
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
		const MeshMemoryData& getIndices();
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
		MeshMemoryData _indices;
		// ��������λ��
		uint8_t _verticeSize = 0;
		// �������� (x,y,z)
		MeshMemoryData _vertices;
		// �������� (x,y,z)
		MeshMemoryData _normals;
		// ��ɫ (r,g,b,a)
		MeshMemoryData _colors;
		// �������� (x,y,z)
		MeshMemoryData _uvs;
		// �任����
		math::Matrix44 _matrix;
	};
}