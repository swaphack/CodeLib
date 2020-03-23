#pragma once

#include "DCColor.h"

namespace render
{
	/**
	*	三角形纹理
	*/
	class DCTextureBatch : public DCColor
	{
	public:
		// 纹理id
		int TextureID;
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
	protected:
		virtual void drawDC();
	public:
		static DCTextureBatch* create(int textureID,
			const sys::Color4B& color, uint8_t opacity, const BlendParam& blend,
			const T_Vertex* vertexes, const T_Vertex* normals, const T_Vertex* colors, const T_Vertex* coords,
			const T_Indice* indices);
	};
}