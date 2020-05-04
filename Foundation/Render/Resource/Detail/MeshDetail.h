#pragma once

#include "system.h"
#include "mathlib.h"

#include <map>

namespace render
{
	/**
	*	�����ڴ�����
	*/
	class MeshMemoryData : public sys::MemoryData
	{
	public:
		MeshMemoryData() {}
		MeshMemoryData(const MeshMemoryData& data)
			:MemoryData(data.getLength(), data.getValue(), data.getUnitSize())
		{
			this->setTypeSize(data.getTypeSize());
		}
		virtual ~MeshMemoryData(){}
	public:
		void setTypeSize(uint32_t size) { _typeSize = size; }
		uint32_t getTypeSize() const { return _typeSize; }
	protected:
	private:
		uint32_t _typeSize = 0;
	};

	/**
	*	��������
	*/
	class MeshDetail : public sys::Object
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
		void setVertices(int size, float* vertexes, int unitSize = 3);
		/**
		*	����������Ϣ
		*/
		const MeshMemoryData& getNormals() const;
		/**
		*	���÷���������Ϣ
		*/
		void setNormals(int size, float* normals, int unitSize = 3);
		/**
		*	��ɫ������Ϣ
		*/
		const MeshMemoryData& getColors() const;
		/**
		*	������ɫ������Ϣ
		*/
		void setColors(int size, float* colors, int unitSize = 3);
		/**
		*	����������Ϣ
		*/
		const MeshMemoryData& getUVs() const;
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
		int getMaterial() const;
		/**
		*	��������������
		*/
		void setIndices(int size, uint32_t* indices);
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