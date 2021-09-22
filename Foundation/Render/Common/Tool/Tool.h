#pragma once

#include "system.h"
#include "Common/struct/import.h"

namespace render
{
	// 窗口工具
	class Tool
	{
	public:
		// 设置视窗大小
		static void setViewSize(float width, float height);
		// 获取视窗大小
		static const math::Size& getViewSize();
		// 获取视图宽度
		static float getViewWidth();
		// 获取视图高度
		static float getViewHeight();
		// 获取水平视域角angle的投影面距离
		static float getHorizontalProjectDistance(float angle);
		// 根据投影面距离和宽高比a，计算垂直视域角
		static float getVerticalAngle(float projDistance, float wDivh);
		// 获取线性插值
		static float getLinearInterpolation(float a, float b, float t);
		// 获取球面线性插值，两个单位向量的线性插值，起点一致
		static math::Vector3 getSphericalLinearInterpolation(const math::Vector3& src, const math::Vector3& dest, float t);
		// 获取四元数线性插值，两个单位
		static math::Quaternion getSphericalLinearInterpolation(const math::Quaternion& src, const math::Quaternion& dest, float t);

		// 角度转弧度
		static math::Vector3 convertToRadian(const math::Vector3& src);
		// 角度转弧度
		static void convertToRadian(const math::Vector3& src, math::Vector3& dest);
		// 弧度转角度
		static math::Vector3 convertToAngle(const math::Vector3& src);
		// 弧度转角度
		static void convertToAngle(const math::Vector3& src, math::Vector3& dest);
		/**
		* 法线的计算
		* @param p1 顶点1
		* @param p2 顶点2
		* @param p3 顶点3
		* @param normal 法线
		*/
		static void calNormal(const math::Vector3& p1, const math::Vector3& p2, const math::Vector3& p3, math::Vector3& normal);
	private:
		// 视窗大小
		static math::Size GL_VIEW_SIZE;
	};
}