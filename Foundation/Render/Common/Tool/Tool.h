#pragma once

#include "system.h"
#include "Common/struct/import.h"

namespace render
{
	// ���ڹ���
	class Tool
	{
	public:
		// �����Ӵ���С
		static void setViewSize(float width, float height);
		// ��ȡ�Ӵ���С
		static const math::Size& getViewSize();
		// ��ȡ��ͼ���
		static float getViewWidth();
		// ��ȡ��ͼ�߶�
		static float getViewHeight();
		// ��ȡˮƽ�����angle��ͶӰ�����
		static float getHorizontalProjectDistance(float angle);
		// ����ͶӰ�����Ϳ�߱�a�����㴹ֱ�����
		static float getVerticalAngle(float projDistance, float wDivh);
		// ��ȡ���Բ�ֵ
		static float getLinearInterpolation(float a, float b, float t);
		// ��ȡ�������Բ�ֵ��������λ���������Բ�ֵ�����һ��
		static math::Vector3 getSphericalLinearInterpolation(const math::Vector3& src, const math::Vector3& dest, float t);
		// ��ȡ��Ԫ�����Բ�ֵ��������λ
		static math::Quaternion getSphericalLinearInterpolation(const math::Quaternion& src, const math::Quaternion& dest, float t);

		// �Ƕ�ת����
		static math::Vector3 convertToRadian(const math::Vector3& src);
		// �Ƕ�ת����
		static void convertToRadian(const math::Vector3& src, math::Vector3& dest);
		// ����ת�Ƕ�
		static math::Vector3 convertToAngle(const math::Vector3& src);
		// ����ת�Ƕ�
		static void convertToAngle(const math::Vector3& src, math::Vector3& dest);
		/**
		* ���ߵļ���
		* @param p1 ����1
		* @param p2 ����2
		* @param p3 ����3
		* @param normal ����
		*/
		static void calNormal(const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3, math::Vector3& normal);
	private:
		// �Ӵ���С
		static math::Size GL_VIEW_SIZE;
	};
}