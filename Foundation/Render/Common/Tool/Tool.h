#pragma once

#include "system.h"
#include "../GL/import.h"

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
		static sys::Vector getRotationPosition(const sys::Vector& vector, const sys::Vector& rotation);
		/**
		* ���ߵļ���
		* @param p1 ����1
		* @param p2 ����2
		* @param p3 ����3
		* @param normal ����
		*/
		static void calNormal(const sys::Vector& p1, const sys::Vector& p2, const sys::Vector& p3, sys::Vector& normal);
		/**
		* ���ζ���ļ���
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		* @param rectVertex ���ζ���
		*/
		static void calRect(const sys::Vector& position, const sys::Volume& volume, const sys::Vector& anchor, RectangeVertex& rectVertex);
		/**
		* ���ζ���ļ���
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		* @param rectVertex ���ζ���
		*/
		static void calRealRect(const sys::Vector& position, const sys::Volume& volume, const sys::Vector& anchor, RectangeVertex& rectVertex);
	private:
		// �Ӵ���С
		static sys::Volume GL_VIEW_SIZE;
	};
}