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
		*	顶点数
		*/
		int getVerticesCount();
		/**
		*	顶点坐标信息
		*/
		const T_Vertex& getVertices();
		/**
		*	设置顶点坐标信息
		*/
		void setVertices(int size, float* vertexes, int unitSize = 3);
		/**
		*	法线坐标信息
		*/
		const T_Vertex& getNormals();
		/**
		*	设置法线坐标信息
		*/
		void setNormals(int size, float* normals, int unitSize = 3);
		/**
		*	颜色坐标信息
		*/
		const T_Vertex& getColors();
		/**
		*	设置颜色坐标信息
		*/
		void setColors(int size, float* colors, int unitSize = 3);
		/**
		*	纹理坐标信息
		*/
		const T_Vertex& getUVs();
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
		int getMaterial();
		/**
		*	设置三角形索引
		*/
		void setIndices(int size, uint32_t* indices);
		/**
		*	获取三角形索引
		*/
		const T_Indice& getIndices();
		/**
		*	获取变换矩阵
		*/
		const math::Matrix44& getMatrix();
		/**
		*	设置变换矩阵
		*/
		void setMatrix(const math::Matrix44& mat);
	private:
		std::string _meshName;
		// 材质
		int _material = 0;
		// 顶点索引
		T_Indice _indices;
		// 顶点坐标 (x,y,z)
		T_Vertex _vertices;
		// 法线坐标 (x,y,z)
		T_Vertex _normals;
		// 颜色 (r,g,b,a)
		T_Vertex _colors;
		// 纹理坐标 (x,y,z)
		T_Vertex _uvs;
		// 变换矩阵
		math::Matrix44 _matrix;
	};
}