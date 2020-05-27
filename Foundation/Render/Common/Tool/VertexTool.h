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
		* @param size 纹理大小
		* @param rect 显示区域
		*/
		static void setTexture2DCoords(RectVertex* texRect, const math::Size& size, const math::Rect& rect);

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
		* @param outUVs[8] 纹理数据
		*/
		static void setTexture2DFlip(float* uvs, bool bFlipX, bool bFlipY);
	};
}