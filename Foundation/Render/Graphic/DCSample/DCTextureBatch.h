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
		// 混色参数
		BlendParam Blend;

		// 顶点坐标 (x,y,z)
		T_Vertex* Vertexes;
		// 法线 (x,y,z)
		T_Vertex* Normals;
		// 颜色 (r,g,b)
		T_Vertex* Colors;
		// 纹理坐标 (x,y,z)
		T_Vertex* TexCoords;
		// 顶点索引
		T_Indice* Indices;
	public:
		DCTextureBatch();
		virtual ~DCTextureBatch();
	public:
		virtual void draw();

		static DCTextureBatch* create(int textureID,
			const sys::Color4B& color, uint8 opacity, const BlendParam& blend,
			const T_Vertex* vertexes, const T_Vertex* normals, const T_Vertex* colors, const T_Vertex* coords,
			const T_Indice* indices);
	};
}