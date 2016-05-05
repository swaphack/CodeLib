#pragma once

#include "system.h"

namespace render
{
	// ���ڹ���
	class Tool
	{
	public:
		// ����opengl�Ӵ���С
		static void setGLViewSize(float width, float height);
		// ��ȡopengl�Ӵ���С
		static const sys::Volume& getGLViewSize();

		// �Ƕ�ת����
		static sys::Vector convertToRadian(const sys::Vector& src);
		// ����ת�Ƕ�
		static sys::Vector convertToAngle(const sys::Vector& src);
		
	private:
		// �Ӵ���С
		static sys::Volume GL_VIEW_SIZE;
	};

	// ģ�͹��� 3d
	class ModelTool
	{
	public:
		// ����Ļ���תΪopengl����
		static sys::Volume convertToOGLVolume(const sys::Volume& src);
	};
}