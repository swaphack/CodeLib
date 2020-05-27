#pragma once

#include "system.h"
#include "Common/struct/import.h"

namespace render
{
	// ���ڹ���
	class Tool
	{
	public:
		// ����opengl�Ӵ���С
		static void setGLViewSize(float width, float height);
		// ��ȡopengl�Ӵ���С
		static const math::Volume& getGLViewSize();

		static float getGLViewWidth();
		static float getGLViewHeight();

		// �Ƕ�ת����
		static math::Vector3 convertToRadian(const math::Vector3& src);
		// �Ƕ�ת����
		static void convertToRadian(const math::Vector3& src, math::Vector3& dest);
		// ����ת�Ƕ�
		static math::Vector3 convertToAngle(const math::Vector3& src);
		// ����ת�Ƕ�
		static void convertToAngle(const math::Vector3& src, math::Vector3& dest);
		
		// ����Ļ����תΪopengl����
		static void convertToOGLPoisition(float* inPos, float* outPos);
		// ����Ļ����תΪopengl����
		static void convertToOGLPoisition(float x, float y, float z, math::Vector3& dest);
		// ����Ļ����תΪopengl����
		static math::Vector3 convertToOGLPoisition(float x, float y, float z);
		// ����Ļ����תΪopengl����
		static math::Vector3 convertToOGLPoisition(const math::Vector3& src);
		// ����Ļ����תΪopengl����
		static void convertToOGLPoisition(const math::Vector3& src, math::Vector3& dest);

		// ��opengl����תΪ��Ļ����
		static math::Vector3 convertToWindowPosition(const math::Vector3& src);
		// ��opengl����תΪ��Ļ����
		static math::Vector3 convertToWindowPosition(float x, float y, float z);

		// ����Ļ���תΪopengl����
		static math::Volume convertToOGLVolume(const math::Volume& src);
		// ��ȡ������ת������
		static math::Vector3 getRotationPosition(const math::Vector3& vector, const math::Vector3& rotation);
		/**
		* ���ߵļ���
		* @param p1 ����1
		* @param p2 ����2
		* @param p3 ����3
		* @param normal ����
		*/
		static void calNormal(const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3, math::Vector3& normal);
		/**
		* ���ζ���ļ���
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		* @param rectVertex ���ζ���
		*/
		static void calRect(const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor, RectVectices& rectVertex);
		/**
		* �����嶥��ļ���
		* @param position λ��
		* @param volume ���
		* @param anchor ê��
		* @param cube ������
		*/
		static void calCube(const math::Vector3& position, const math::Volume& volume, const math::Vector3& anchor, CubeVectices& cube);
	private:
		// �Ӵ���С
		static math::Volume GL_VIEW_SIZE;
	};
}