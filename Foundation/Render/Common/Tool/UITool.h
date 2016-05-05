#pragma once

#include "system.h"

namespace render
{
	// ���湤�� 2d
	class UITool
	{
	public:
		// ����Ļ����תΪopengl����
		static void convertToOGLPoisition(float x, float y, float z, sys::Vector& dest);
		// ����Ļ����תΪopengl����
		static sys::Vector convertToOGLPoisition(float x, float y, float z);
		// ����Ļ����תΪopengl����
		static sys::Vector convertToOGLPoisition(const sys::Vector& src);
		// ����Ļ����תΪopengl����
		static void convertToOGLPoisition(const sys::Vector& src, sys::Vector& dest);


		// ��opengl����תΪ��Ļ����
		static sys::Vector convertToWindowPosition(const sys::Vector& src);
		// ��opengl����תΪ��Ļ����
		sys::Vector convertToWindowPosition(float x, float y, float z);
	};
}