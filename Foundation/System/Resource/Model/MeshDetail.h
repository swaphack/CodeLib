#pragma once

#include "Memory/MemoryData.h"
#include "Framework/Object.h"
#include "mathlib.h"
#include <map>

namespace sys
{
	/**
	*	�����ڴ�����
	*/
	class MeshMemoryData : public MemoryData
	{
	public:
		MeshMemoryData() {}
		MeshMemoryData(const MeshMemoryData& data)
			:MemoryData(data.getLength(), data.getValue(), data.getTypeSize())
		{
			this->setUnitSize(data.getUnitSize());
		}
		virtual ~MeshMemoryData(){}
	public:
		void setUnitSize(uint32_t size) { _unitSize = size; }
		uint32_t getUnitSize() const { return _unitSize; }
	protected:
	private:
		// ÿ����λ��С
		uint32_t _unitSize = 0;
	};

	/**
	*	��������
	*/
	class MeshDetail : public Object
	{
	public:
		MeshDetail();
		virtual ~MeshDetail();
	public:
		const std::string& getMeshName() const;

		void setMeshName(const std::string& name);
		/**
		*	����������Ϣ
		*/
		const MeshMemoryData& getVertices() const;
		/**
		*	���ö���������Ϣ
		*/
		void setVertices(int len, const float* vertexes, int unitSize = 3);
		/**
		*	����������Ϣ
		*/
		const MeshMemoryData& getNormals() const;
		/**
		*	���÷���������Ϣ
		*/
		void setNormals(int len, const float* normals, int unitSize = 3);
		/**
		*	��ɫ������Ϣ
		*/
		const MeshMemoryData& getColors() const;
		/**
		*	������ɫ������Ϣ
		*/
		void setColors(int len, const float* colors, int unitSize = 4);
		/**
		*	����������Ϣ
		*/
		const MeshMemoryData& getUVs() const;
		/**
		*	��������������Ϣ
		*/
		void setUVs(int len, const float* texCoords, int unitSize = 2);
		/**
		*	���ò���
		*/
		void setMaterial(int mat);
		/**
		*	��ȡ����
		*/
		int getMaterial() const;
		/**
		*	��������������
		*/
		void setIndices(int size, const uint32_t* indices, int unitSize = 1);
		/**
		*	��ȡ����������
		*/
		const MeshMemoryData& getIndices() const;
		/**
		*	��ȡ�任����
		*/
		const math::Matrix44& getMatrix() const;
		/**
		*	���ñ任����
		*/
		void setMatrix(const math::Matrix44& mat);
	public:
		/**
		*	���䶥��
		*/
		char* createVertices(size_t len, uint32_t typeSize, int unitSize = 3);
		/**
		*	���䷨��
		*/
		char* createNormals(size_t len, uint32_t typeSize, int unitSize = 3);
		/**
		*	������ɫ
		*/
		char* createColors(size_t len, uint32_t typeSize, int unitSize = 4);
		/**
		*	������������
		*/
		char* createUVs(size_t len, uint32_t typeSize, int unitSize = 2);
		/**
		*	���䶥������
		*/
		char* createIndices(size_t len, uint32_t typeSize, int unitSize = 1);
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