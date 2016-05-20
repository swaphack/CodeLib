#pragma once

#include "../GL/import.h"

namespace render
{
	class GLTool
	{
	public:
		/**
		* 绘制矩形纹理
		* @param texID 纹理id
		* @param texRect 纹理四个顶点坐标
		*/
		static void drawRectVertex(const TextureRect* texRect);
		/**
		* 绘制三角形纹理
		* @param texID 纹理id
		* @param texRect 纹理四个顶点坐标
		*/
		static void drawTriangleVertex(const TextureRect* texRect);

		/**
		* 绘制立方体纹理
		* @param texID 纹理id
		* @param texRect 纹理四个顶点坐标
		* @param normal 法线
		*/
		static void drawRectVertexWithNormal(const TextureRect* texRect, const sys::Vector& normal);

		/**
		* 绘制颜色
		* @param red
		* @param green
		* @param blue
		* @param alpha
		*/
		static void setColor(uchar red, uchar green, uchar blue, uchar alpha);
		/**
		* 绘制颜色
		* @param color
		*/
		static void setColor(sys::Color4B color);
		/**
		* 绘制矩形
		* @param rectVertex 矩形四个顶点坐标
		* @param type 类型
		*/
		static void drawRect(const RectangeVertex* rectVertex, uint type);

		/**
		* 法线的计算
		* @param p1 顶点1
		* @param p2 顶点2
		* @param p3 顶点3
		* @param normal 法线
		*/
		static void calNormal(const sys::Vector& p1, const sys::Vector& p2, const sys::Vector& p3, sys::Vector& normal);
		/**
		* 矩形顶点的计算
		* @param position 位置
		* @param volume 体积
		* @param anchor 锚点
		* @param rectVertex 矩形顶点
		*/
		static void calRect(const sys::Vector& position, const sys::Volume& volume, const sys::Vector& anchor, RectangeVertex& rectVertex);

		/**
		* 开始混合
		* @param blend 混合条件
		*/
		static void beginBlend(const BlendParam& blend);
		/**
		* 开始混合
		* @param src 混合条件
		* @param dest 混合条件
		*/
		static void beginBlend(int src, int dest);
		/**
		* 混合结束
		*/
		static void endBlend();
	};
}