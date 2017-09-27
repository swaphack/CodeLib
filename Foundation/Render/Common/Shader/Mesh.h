#pragma once

#include "system.h"
#include "../GL/pointer_common.h"
#include "../GL/texture_common.h"

namespace render
{
	// 纹理网格
	class Mesh : public sys::Object
	{
	public:
		Mesh();
		virtual ~Mesh();
	public:
		/** 
		*	设置顶点坐标信息
		*	@param count 数组长度
		*	@param vertexes 顶点坐标（xyz）
		*	@param size 每个元素大小 3
		*/
		void setVertexes(int count, float* vertexes);
		/**
		*	设置法线坐标信息
		*	@param count 数组长度
		*	@param normals 法线坐标（xyz）
		*	@param size 每个元素大小 3
		*/
		void setNormals(int count, float* normals);
		/**
		*	设置颜色坐标信息
		*	@param count 数组长度
		*	@param colors 颜色（rgba 255）
		*	@param size 每个元素大小 3或4
		*/
		void setColors(int count, float* colors, int size);
		/**
		*	设置纹理坐标信息
		*	@param count 数组长度
		*	@param texCoords 纹理坐标（uv）
		*	@param size 每个元素大小 2或3
		*/
		void setUV(int count, float* texCoords, int size);

		// 顶点数
		int getVertexCount();

		// 三角形数
		int getTriangleCount();
		/**
		*	设置三角形索引
		*	@param count 三角形顶点数
		*	@param indices 顶点索引
		*/
		void setIndices(int count, ushort* indices);
		/**
		*	绘制
		*	@param textureID 纹理id
		*	@param color 颜色
		*/
		void apply(int textureID, const sys::Color4B& color, uchar opacity, const BlendParam& blend);
	protected:
		// 顶点坐标 (x,y,z)
		T_Vertex _vertexes;
		// 法线坐标 (x,y,z)
		T_Vertex _normals;
		// 颜色 (r,g,b,a)
		T_Vertex _colors;
		// 纹理坐标 (x,y,z)
		T_Vertex _uvs;
		// 顶点索引
		T_Indice _indices;
	};
}