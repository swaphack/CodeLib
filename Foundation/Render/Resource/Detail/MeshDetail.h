#pragma once

#include "system.h"
#include "mathlib.h"

#include <map>

namespace render
{
	/**
	*	网格内存数据
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
	*	网格数据
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
		*	顶点坐标信息
		*/
		const MeshMemoryData& getVertices() const;
		/**
		*	设置顶点坐标信息
		*/
		void setVertices(int size, float* vertexes, int unitSize = 3);
		/**
		*	法线坐标信息
		*/
		const MeshMemoryData& getNormals() const;
		/**
		*	设置法线坐标信息
		*/
		void setNormals(int size, float* normals, int unitSize = 3);
		/**
		*	颜色坐标信息
		*/
		const MeshMemoryData& getColors() const;
		/**
		*	设置颜色坐标信息
		*/
		void setColors(int size, float* colors, int unitSize = 3);
		/**
		*	纹理坐标信息
		*/
		const MeshMemoryData& getUVs() const;
		/**
		*	设置纹理坐标信息
		*/
		void setUVs(int size, float* texCoords, int unitSize = 2);
		/**
		*	设置材质
		*/
		void setMaterial(int mat);
		/**
		*	获取材质
		*/
		int getMaterial() const;
		/**
		*	设置三角形索引
		*/
		void setIndices(int size, uint32_t* indices);
		/**
		*	获取三角形索引
		*/
		const MeshMemoryData& getIndices() const;
		/**
		*	获取变换矩阵
		*/
		const math::Matrix44& getMatrix() const;
		/**
		*	设置变换矩阵
		*/
		void setMatrix(const math::Matrix44& mat);
	private:
		std::string _meshName;
		// 材质
		int _material = 0;
		
		// 顶点索引
		MeshMemoryData _indices;
		// 顶点坐标位数
		uint8_t _verticeSize = 0;
		// 顶点坐标 (x,y,z)
		MeshMemoryData _vertices;
		// 法线坐标 (x,y,z)
		MeshMemoryData _normals;
		// 颜色 (r,g,b,a)
		MeshMemoryData _colors;
		// 纹理坐标 (x,y,z)
		MeshMemoryData _uvs;
		// 变换矩阵
		math::Matrix44 _matrix;
	};
}