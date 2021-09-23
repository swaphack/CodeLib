#pragma once

#include "Memory/MemoryData.h"
#include "Framework/Object.h"
#include "mathlib.h"
#include <map>

namespace sys
{
	/**
	*	网格内存数据
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
		// 每个单位大小
		uint32_t _unitSize = 0;
	};

	/**
	*	网格数据
	*/
	class MeshDetail : public Object
	{
	public:
		MeshDetail();
		virtual ~MeshDetail();
	public:
		/**
		*	名称
		*/
		const std::string& getName() const;
		/**
		*	设置名称
		*/
		void setName(const std::string& name);
		/**
		*	顶点坐标信息
		*/
		const MeshMemoryData& getVertices() const;
		/**
		*	设置顶点坐标信息
		*/
		void setVertices(int len, const float* vertexes, int unitSize = 3);
		/**
		*	法线坐标信息
		*/
		const MeshMemoryData& getNormals() const;
		/**
		*	设置法线坐标信息
		*/
		void setNormals(int len, const float* normals, int unitSize = 3);
		/**
		*	切线坐标信息
		*/
		const MeshMemoryData& getTangents() const;
		/**
		*	设置切线坐标信息
		*/
		void setTangents(int len, const float* normals, int unitSize = 3);
		/**
		*	辅助切线坐标信息
		*/
		const MeshMemoryData& getBitangents() const;
		/**
		*	设置辅助切线坐标信息
		*/
		void setBitangents(int len, const float* normals, int unitSize = 3);
		/**
		*	颜色坐标信息
		*/
		const MeshMemoryData& getColors() const;
		/**
		*	设置颜色坐标信息
		*/
		void setColors(int len, const float* colors, int unitSize = 4);
		/**
		*	纹理坐标信息
		*/
		const MeshMemoryData& getUVs() const;
		/**
		*	设置纹理坐标信息
		*/
		void setUVs(int len, const float* texCoords, int unitSize = 2);
		/**
		*	设置材质
		*/
		void setMaterial(const std::string& name);
		/**
		*	获取材质
		*/
		const std::string& getMaterial() const;
		/**
		*	设置三角形索引
		*/
		void setIndices(int size, const uint32_t* indices, int unitSize = 1);
		/**
		*	获取三角形索引
		*/
		const MeshMemoryData& getIndices() const;
		/**
		*	获取变换矩阵
		*/
		const math::Matrix4x4& getMatrix() const;
		/**
		*	设置变换矩阵
		*/
		void setMatrix(const math::Matrix4x4& mat);
	public:
		/**
		*	分配顶点
		*/
		char* createVertices(size_t len, uint32_t typeSize, int unitSize = 3);
		/**
		*	分配法线
		*/
		char* createNormals(size_t len, uint32_t typeSize, int unitSize = 3);
		/**
		*	分配切线
		*/
		char* createTangents(size_t len, uint32_t typeSize, int unitSize = 3);
		/**
		*	分配辅助切线
		*/
		char* createBitangents(size_t len, uint32_t typeSize, int unitSize = 3);
		/**
		*	分配颜色
		*/
		char* createColors(size_t len, uint32_t typeSize, int unitSize = 4);
		/**
		*	分配纹理坐标
		*/
		char* createUVs(size_t len, uint32_t typeSize, int unitSize = 2);
		/**
		*	分配顶点索引
		*/
		char* createIndices(size_t len, uint32_t typeSize, int unitSize = 1);
	private:
		std::string _meshName;
		// 材质
		std::string _materialName;
		
		// 顶点索引
		MeshMemoryData _indices;
		// 顶点坐标 (x,y,z)
		MeshMemoryData _vertices;
		// 法线坐标 (x,y,z)
		MeshMemoryData _normals;
		// 颜色 (r,g,b,a)
		MeshMemoryData _colors;
		// 纹理坐标 (x,y,z)
		MeshMemoryData _uvs;
		// tangent坐标 (x,y,z)
		MeshMemoryData _tangents;
		// bitangent坐标 (x,y,z)
		MeshMemoryData _bitangents;
		// 变换矩阵
		math::Matrix4x4 _matrix;
	};
}