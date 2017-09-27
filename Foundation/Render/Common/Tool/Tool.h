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

		// ��ȡ��ǰά��ģʽ��2d����3d
		static Dimensions getDimensions();
		static void setDimensions(Dimensions d);

		// �Ƕ�ת����
		static sys::Vector3 convertToRadian(const sys::Vector3& src);
		// ����ת�Ƕ�
		static sys::Vector3 convertToAngle(const sys::Vector3& src);
		
		// ����Ļ����תΪopengl����
		static void convertToOGLPoisition(float x, float y, float z, sys::Vector3& dest);
		// ����Ļ����תΪopengl����
		static sys::Vector3 convertToOGLPoisition(float x, float y, float z);
		// ����Ļ����תΪopengl����
		static sys::Vector3 convertToOGLPoisition(const sys::Vector3& src);
		// ����Ļ����תΪopengl����
		static void convertToOGLPoisition(const sys::Vector3& src, sys::Vector3& dest);

		// ��opengl����תΪ��Ļ����
		static sys::Vector3 convertToWindowPosition(const sys::Vector3& src);
		// ��opengl����תΪ��Ļ����
		sys::Vector3 convertToWindowPosition(float x, float y, float z);

		// ����Ļ���תΪopengl����
		static sys::Volume convertToOGLVolume(const sys::Volume& src);
		// ��ȡ������ת������
		static sys::Vector3 getRotationPosition(const sys::Vector3& vector, const sys::Vector3& rotation);
		/**
		* ���ߵļ���
		* @param p1 ����1
		* @param p2 ����2
		* @param p3 ����3
		* @param normal ����
		*/
		static void calNormal(const sys::Vector3& p1, const sys::Vector3& p2, const sys::Vector3& p3, sys::Vector3& normal);
		/**
		* ���ζ���ļ���
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		* @param rectVertex ���ζ���
		*/
		static void calRect(const sys::Vector3& position, const sys::Volume& volume, const sys::Vector3& anchor, RectangeVertex& rectVertex);
		/**
		* ���ζ���ļ���
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		* @param rectVertex ���ζ���
		*/
		static void calRealRect(const sys::Vector3& position, const sys::Volume& volume, const sys::Vector3& anchor, RectangeVertex& rectVertex);

		static float getGLViewWidth();
		static float getGLViewHeight();
	private:
		// �Ӵ���С
		static sys::Volume GL_VIEW_SIZE;
		// ά��ģʽ
		static Dimensions E_DIMENSIONS;
	};
}