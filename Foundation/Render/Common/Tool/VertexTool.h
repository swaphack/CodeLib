#pragma once

#include "Common/struct/import.h"

namespace render
{
	class VertexTool
	{
	public:
		/**
		*
		* 设置2d纹理坐标 逆时针
		* @param texRect 纹理数据 out
		* @param rect 显示区域
		* @param rotate 是否发生旋转
		*/
		static void setTexture2DCoords(RectVertex* texRect, const math::Rect& rect, bool rotate);

		/**
		*
		* 设置2d纹理顶点位置
		* @param texRect 纹理数据 out
		* @param position 位置
		* @param volume 体积
		* @param anchor 锚点
		*/
		static void setTexture2DVertices(RectVertex* texRect, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor);

		/**
		*
		* 设置3d纹理顶点位置
		* @param texcube 纹理数据 out
		* @param position 位置
		* @param volume 体积
		* @param anchor 锚点
		*/
		static void setTexture3DVertices(CubeVertex* texcube, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor);
		/**
		*
		* 设置2d纹理顶点翻转
		* @param uvs[8] 纹理数据
		* @param bFlipX 是否水平翻转
		* @param bFlipY 是否垂直翻转
		*/
		static void setTexture2DFlip(float(*uvs)[8], bool bFlipX, bool bFlipY);

		/**
		*
		* 设置九宫格2d纹理坐标 逆时针
		* @param scale9Vertex 纹理数据 out
		* @param rect 占据的位置和大小
		* @param rotate 是否旋转
		* @param margin 留白
		*/
		static void setTexture2DScale9Coords(SimpleScale9Vertex* scale9Vertex, const math::Rect& rect, bool rotate, const math::Size& size, const sys::CSSMargin& margin);

		/**
		*
		* 设置九宫格2d纹理顶点位置
		* @param scale9Vertex 纹理数据 out
		* @param position 位置
		* @param volume 体积
		* @param anchor 锚点
		*/
		static void setTexture2DScale9Vertices(SimpleScale9Vertex* scale9Vertex, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor, const sys::CSSMargin& margin);
		/**
		*
		* 设置九宫格2d2d纹理顶点翻转
		* @param uvs[32] 纹理数据
		* @param bFlipX 是否水平翻转
		* @param bFlipY 是否垂直翻转
		*/
		static void setTexture2DScale9Flip(float(*uvs)[32], bool bFlipX, bool bFlipY);
	};
}