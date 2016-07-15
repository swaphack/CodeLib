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
		static void setColor(const sys::Color4B& color);
		/**
		* 绘制矩形
		* @param rectVertex 矩形四个顶点坐标
		* @param type 类型
		*/
		static void drawRect(const RectangeVertex* rectVertex, uint type);

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