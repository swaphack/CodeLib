#pragma once

#include "macros.h"

namespace render
{
	/**
	*	三角形纹理
	*/
	class DCTextureBatch : public DrawCommand
	{
	public:
		// 纹理id
		int TextureID;
		// 颜色
		sys::Color4F Color;

		// 顶点数
		int VertexCount;
		// 顶点坐标 (x,y,z)
		float* Vertexs;
		// 法线 (x,y,z)
		float* Normals;
		// 颜色 (r,g,b)
		float* Colors;
		// 纹理坐标 (x,y,z)
		float* TexCoords;

		// 顶点数
		int IndexCount;
		// 顶点索引
		ushort* Indices;

		// 混色参数
		BlendParam Blend;
	public:
		DCTextureBatch();
		virtual ~DCTextureBatch();
	public:
		virtual void draw();

		static DCTextureBatch* create(int textureID,
			const sys::Color4B& color, uchar opacity, const BlendParam& blend,
			int vertexCount, float* normals, float* positions, float* colors, float* coords,
			int indexCount, ushort* indices);
	};
}