#pragma once

#include "system.h"

namespace render
{
	// 界面工具 2d
	class UITool
	{
	public:
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
	};
}