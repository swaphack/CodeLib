#pragma once

#include "../GL/import.h"

namespace render
{
	class TextureTool
	{
	public:
		/**
		*
		* 设置2d纹理坐标 顺时针
		* @param texRect 纹理数据 out
		* @param size 纹理大小
		* @param rect 显示区域
		*/ 
		static void setTexture2DCounterCoords(TextureRect* texRect, const sys::Size& size, const sys::Rect& rect);

		/**
		*
		* 设置2d纹理坐标 逆时针
		* @param texRect 纹理数据 out
		* @param size 纹理大小
		* @param rect 显示区域
		*/
		static void setTexture2DCoords(TextureRect* texRect, const sys::Size& size, const sys::Rect& rect);

		/**
		*
		* 设置2d纹理顶点位置
		* @param texRect 纹理数据 out
		* @param position 位置
		* @param volume 体积
		* @param anchor 锚点
		*/
		static void setTexture2DVertexts(TextureRect* texRect, const sys::Vector& position, const sys::Volume& volume, const sys::Vector& anchor);

		/**
		* 设置3d纹理坐标
		* @param texcube 纹理数据 out
		* @param size 纹理大小
		* @param rect 显示区域
		*/
		/*static void setTexture3DCoords(TextureCube* texcube, const sys::Size& size, const sys::Rect& rect);*/

		/**
		*
		* 设置3d纹理顶点位置
		* @param texcube 纹理数据 out
		* @param position 位置
		* @param volume 体积
		* @param anchor 锚点
		*/
		static void setTexture3DVertexts(TextureCube* texcube, const sys::Vector& position, const sys::Volume& volume, const sys::Vector& anchor);
		/**
		*
		* 设置2d纹理顶点翻转
		* @param texcube 纹理数据 out
		* @param bFlipX 是否水平翻转
		* @param bFlipY 是否垂直翻转
		*/
		static void setTexture2DFlip(TextureRect* texRect, bool bFlipX, bool bFlipY);
	};
}