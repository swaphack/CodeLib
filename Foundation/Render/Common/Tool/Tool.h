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

		// ����Ļ���תΪopengl����
		static sys::Volume convertToOGLVolume(const sys::Volume& src);
		// ��ȡ������ת������
		static sys::Vector getPosition(const sys::Vector& vector, const sys::Vector& rotation);
	private:
		// �Ӵ���С
		static sys::Volume GL_VIEW_SIZE;
	};
}