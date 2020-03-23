#pragma once

#include "system.h"

#include "Common/struct/pointer_common.h"
#include <map>

namespace render
{
	class Face; 

	class Mesh : public sys::Object
	{
	public:
		Mesh();
		virtual ~Mesh();
	public:
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
		*	添加面
		*/
		void addFace(int id, Face* face);
		/**
		*	移除面
		*/
		void removeFace(int id);
		/**
		*	获取面
		*/
		Face* getFace(int id);
		/**
		*	移除所有面
		*/
		void removeAllFaces();
		/**
		*	获取所有面
		*/
		const std::map<int, Face*>& getFaces();
	private:
		// 面
		std::map<int, Face*> _faces;
		// 顶点坐标 (x,y,z)
		T_Vertex _vertices;
		// 法线坐标 (x,y,z)
		T_Vertex _normals;
		// 颜色 (r,g,b,a)
		T_Vertex _colors;
		// 纹理坐标 (x,y,z)
		T_Vertex _uvs;
	};
}