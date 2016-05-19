#pragma once

#include "system.h"

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

		// 角度转弧度
		static sys::Vector convertToRadian(const sys::Vector& src);
		// 弧度转角度
		static sys::Vector convertToAngle(const sys::Vector& src);
		
		// 将屏幕坐标转为opengl坐标
		static void convertToOGLPoisition(float x, float y, float z, sys::Vector& dest);
		// 将屏幕坐标转为opengl坐标
		static sys::Vector convertToOGLPoisition(float x, float y, float z);
		// 将屏幕坐标转为opengl坐标
		static sys::Vector convertToOGLPoisition(const sys::Vector& src);
		// 将屏幕坐标转为opengl坐标
		static void convertToOGLPoisition(const sys::Vector& src, sys::Vector& dest);

		// 将opengl坐标转为屏幕坐标
		static sys::Vector convertToWindowPosition(const sys::Vector& src);
		// 将opengl坐标转为屏幕坐标
		sys::Vector convertToWindowPosition(float x, float y, float z);

		// 将屏幕体积转为opengl坐标
		static sys::Volume convertToOGLVolume(const sys::Volume& src);
		// 获取经过旋转的坐标
		static sys::Vector getPosition(const sys::Vector& vector, const sys::Vector& rotation);
	private:
		// 视窗大小
		static sys::Volume GL_VIEW_SIZE;
	};
}