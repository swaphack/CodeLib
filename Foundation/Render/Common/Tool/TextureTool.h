#pragma once

#include "Common/struct/import.h"

namespace render
{
	class TextureTool
	{
	public:
		/**
		*
		* 设置2d纹理坐标 逆时针
		* @param texRect 纹理数据 out
		* @param size 纹理大小
		* @param rect 显示区域
		*/
		static void setTexture2DCoords(TextureRectVertex* texRect, const math::Size& size, const math::Rect& rect);

		/**
		*
		* 设置2d纹理顶点位置
		* @param texRect 纹理数据 out
		* @param position 位置
		* @param volume 体积
		* @param anchor 锚点
		*/
		static void setTexture2DVertexts(TextureRectVertex* texRect, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor);

		/**
		*
		* 设置3d纹理顶点位置
		* @param texcube 纹理数据 out
		* @param position 位置
		* @param volume 体积
		* @param anchor 锚点
		*/
		static void setTexture3DVertexts(TextureCubeVertex* texcube, const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor);
		/**
		*
		* 设置2d纹理顶点翻转
		* @param texcube 纹理数据 out
		* @param bFlipX 是否水平翻转
		* @param bFlipY 是否垂直翻转
		*/
		static void setTexture2DFlip(TextureRectVertex* texRect, bool bFlipX, bool bFlipY);
	};
}