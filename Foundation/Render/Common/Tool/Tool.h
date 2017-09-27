#pragma once

#include "system.h"
#include "../GL/import.h"

namespace render
{
	// 窗口工具
	class Tool
	{
	public:
		// 设置opengl视窗大小
		static void setGLViewSize(float width, float height);
		// 获取opengl视窗大小
		static const sys::Volume& getGLViewSize();

		// 获取当前维度模式，2d还是3d
		static Dimensions getDimensions();
		static void setDimensions(Dimensions d);

		// 角度转弧度
		static sys::Vector3 convertToRadian(const sys::Vector3& src);
		// 弧度转角度
		static sys::Vector3 convertToAngle(const sys::Vector3& src);
		
		// 将屏幕坐标转为opengl坐标
		static void convertToOGLPoisition(float x, float y, float z, sys::Vector3& dest);
		// 将屏幕坐标转为opengl坐标
		static sys::Vector3 convertToOGLPoisition(float x, float y, float z);
		// 将屏幕坐标转为opengl坐标
		static sys::Vector3 convertToOGLPoisition(const sys::Vector3& src);
		// 将屏幕坐标转为opengl坐标
		static void convertToOGLPoisition(const sys::Vector3& src, sys::Vector3& dest);

		// 将opengl坐标转为屏幕坐标
		static sys::Vector3 convertToWindowPosition(const sys::Vector3& src);
		// 将opengl坐标转为屏幕坐标
		sys::Vector3 convertToWindowPosition(float x, float y, float z);

		// 将屏幕体积转为opengl坐标
		static sys::Volume convertToOGLVolume(const sys::Volume& src);
		// 获取经过旋转的坐标
		static sys::Vector3 getRotationPosition(const sys::Vector3& vector, const sys::Vector3& rotation);
		/**
		* 法线的计算
		* @param p1 顶点1
		* @param p2 顶点2
		* @param p3 顶点3
		* @param normal 法线
		*/
		static void calNormal(const sys::Vector3& p1, const sys::Vector3& p2, const sys::Vector3& p3, sys::Vector3& normal);
		/**
		* 矩形顶点的计算
		* @param position 位置
		* @param volume 体积
		* @param anchor 锚点
		* @param rectVertex 矩形顶点
		*/
		static void calRect(const sys::Vector3& position, const sys::Volume& volume, const sys::Vector3& anchor, RectangeVertex& rectVertex);
		/**
		* 矩形顶点的计算
		* @param position 位置
		* @param volume 体积
		* @param anchor 锚点
		* @param rectVertex 矩形顶点
		*/
		static void calRealRect(const sys::Vector3& position, const sys::Volume& volume, const sys::Vector3& anchor, RectangeVertex& rectVertex);

		static float getGLViewWidth();
		static float getGLViewHeight();
	private:
		// 视窗大小
		static sys::Volume GL_VIEW_SIZE;
		// 维度模式
		static Dimensions E_DIMENSIONS;
	};
}