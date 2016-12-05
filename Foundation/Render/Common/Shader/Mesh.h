#pragma once

#include "macros.h"

namespace render
{
	// 纹理网格
	class Mesh : public sys::Object
	{
	public:
		Mesh();
		virtual ~Mesh();
	public:
		// 设置顶点,法线，纹理坐标信息
		void setVertexes(int count, float* vertexes, float* normals, float* colors, float* texCoords);
		// 设置三角形索引
		void setIndices(int count, ushort* indices);
		// 顶点数
		int getVertexCount();
		// 三角形数
		int getTriangleCount();

		void apply(int textureID, const sys::Color4B& color, uchar opacity, const BlendParam& blend);
	protected:
		// 顶点数
		int _vertexCount;
		// 顶点坐标 (x,y,z)
		float* _vertexes;
		// 法线 (x,y,z)
		float* _normals;
		// 颜色 (r,g,b)
		float* _colors;
		// 纹理坐标 (x,y,z)
		float* _texCoords;

		// 三角形数
		int _triangleCount;
		// 顶点索引
		ushort* _indices;
	};
}