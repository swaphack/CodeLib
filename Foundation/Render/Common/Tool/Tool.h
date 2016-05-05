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
		
	private:
		// 视窗大小
		static sys::Volume GL_VIEW_SIZE;
	};

	// 模型工具 3d
	class ModelTool
	{
	public:
		// 将屏幕体积转为opengl坐标
		static sys::Volume convertToOGLVolume(const sys::Volume& src);
	};
}