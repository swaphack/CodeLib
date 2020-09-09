#pragma once

#include <cstdlib>
#include "Algebra/import.h"

namespace math
{
	/**
	*	立体几何的面
	*/
	template<typename T,
		const int Length,
		typename = std::enable_if<std::is_base_of<math::Vector3, T>::value, T>::type>
	struct Surface3d : public Array<T, Length>
	{
	public:
		Surface3d() {}
		Surface3d(const Surface3d& surface) 
		{
			this->assign(surface.getValue());
		}
		Surface3d(const T* poins)
		{
			this->assign(poins);
		}

		virtual ~Surface3d() {}
	public:
		/**
		*	法向量
		*/
		Vector3 normalVector() const
		{
			Vector3 v0 = (*this)[1] - (*this)[0];
			Vector3 v1 = (*this)[2] - (*this)[1];

			return Vector3::cross(v0, v1);
		}
		/**
		*	是否包含点
		*	先判断是否共面，再判断投影是否包含
		*/
		bool contains(const Vector3& point)
		{
			if (!isCoplanar(*this, point))
			{ // 不共面
				return false;
			}

			Vector2 pxy(point.getX(), point.getY());
			Vector2 pyz(point.getY(), point.getZ());
			Vector2 pxz(point.getX(), point.getZ());

			Polygon2d pxoy = Surface3d::projectOnXOY(*this);
			Polygon2d pyoz = Surface3d::projectOnXOY(*this);
			Polygon2d pxoz = Surface3d::projectOnXOY(*this);

			if (pxoy.contains(pxy) || pyoz.contains(pyz) || pyoz.contains(pxz))
			{
				return true;
			}

			return false;
		}
		/**
		*	重载=
		*/
		Surface3d& operator=(const Surface3d& surface)
		{
			this->assign(surface.getValue());
		}
	public:
		/**
		*	是否是标准的多边形，顶点数大于等于3,并且相邻不存在共线的情况
		*	且共面
		*/
		static bool isStandard(const Surface3d& surface)
		{
			if (surface.getLength() < 3)
			{
				return false;
			}

			int32_t lineCount = surface.getLength();
			for (int32_t i = 0; i < lineCount; i++)
			{
				// 邻边的向量
				Vector3 l0 = surface[(i + 1) % lineCount] - surface[i % lineCount];
				Vector3 l1 = surface[(i + 2) % lineCount] - surface[(i + 1) % lineCount];
				Vector3 l2 = surface[(i + 3) % lineCount] - surface[(i + 2) % lineCount];
				// 两向量所在平面的法向量
				Vector3 n0 = Vector3::cross(l0, l1);
				Vector3 n1 = Vector3::cross(l1, l2);
				if (Vector3::dot(n0, n1) != 0)
				{ // 法向量不共线
					return false;
				}
				if (n0.getX() * n1.getX() < 0)
				{// 法向量不同向
					return false;
				}
			}

			return true;
		}
		/**
		*	是否是凸多边形
		*/
		static bool isConvex(const Surface3d& surface)
		{
			if (!isStandard(surface))
			{
				return false;
			}
			/*
			int32_t lineCount = surface.getLength() - 2;
			int32_t lastDirection = -1;
			for (int32_t i = 0; i < lineCount; i++)
			{
				Vector3 l0 = surface[(i + 1) % lineCount] - surface[i % lineCount];
				Vector3 l1 = surface[(i + 2) % lineCount] - surface[(i + 1) % lineCount];

				int32_t direction = Vector3::direction(l1, l0);
				if (lastDirection == -1)
				{
					lastDirection = direction;
				}
				else if (direction != lastDirection)
				{
					return false;
				}
			}

			return true;
			*/
			return false;
		}
		/**
		*	点与平面是否共面
		*/
		static bool isCoplanar(const Surface3d& surface, const Vector3& point)
		{
			if (!isStandard(surface))
			{
				return false;
			}
			int32_t lineCount = surface.getLength();
			// 邻边的向量
			Vector3 l0 = surface[1] - surface[0];
			Vector3 l1 = surface[2] - surface[1];
			Vector3 l2 = point - surface[2];
			// 法向量
			Vector3 n0 = Vector3::cross(l0, l1);
			Vector3 n1 = Vector3::cross(l1, l2);
			if (Vector3::dot(n0, n1) != 0)
			{ // 法向量不共线
				return false;
			}
			if (n0.getX() * n1.getX() < 0)
			{// 法向量不同向
				return false;
			}

			return true;
		}
		/**
		*	四点是否共面
		*/
		static bool canMakeCoplanar(const Vector3& point0, const Vector3& point1, const Vector3& point2,
			const Vector3& point3)
		{
			// 邻边的向量
			Vector3 l0 = point1 - point0;
			Vector3 l1 = point2 - point1;
			Vector3 l2 = point3 - point2;

			if (Vector3::isThreePointsOnSameLine(point0, point1, point2))
			{ // 相邻共线，构成不了平面
				return false;
			}

			// 法向量
			Vector3 n0 = Vector3::cross(l0, l1);
			Vector3 n1 = Vector3::cross(l1, l2);
			if (Vector3::dot(n0, n1) != 0)
			{ // 法向量不共线
				return false;
			}
			if (n0.getX() * n1.getX() < 0)
			{// 法向量不同向
				return false;
			}

			return true;
		}
		/**
		*	投影到xoy面
		*/
		static Polygon2d<Length> projectOnXOY(const Surface3d& surface)
		{
			int32_t count = surface.getLength();
			// 投影坐标计算
			Vector2* ps = new Vector2[count];
			for (int32_t i = 0; i < count; i++)
			{
				float x = surface[i].getX();
				float y = surface[i].getY();
				ps[i].setX(x);
				ps[i].setY(y);
			}

			// 投影
			Polygon2d<Length> polygon(ps);
			delete[] ps;

			return polygon;
		}
		/**
		*	投影到yoz面
		*/
		static Polygon2d<Length> projectOnYOZ(const Surface3d& surface)
		{
			int32_t count = surface.getLength();
			// 投影坐标计算
			Vector2* ps = new Vector2[count];
			for (int32_t i = 0; i < count; i++)
			{
				float x = surface[i].getX();
				float y = surface[i].getY();
				ps[i].setX(x);
				ps[i].setY(y);
			}

			// 投影
			Polygon2d<Length> polygon(ps);
			delete[] ps;

			return polygon;
		}
		/**
		*	投影到xoz面
		*/
		static Polygon2d<Length> projectOnXOZ(const Surface3d& surface)
		{
			int32_t count = surface.getLength();
			// 投影坐标计算
			Vector2* ps = new Vector2[count];
			for (int32_t i = 0; i < count; i++)
			{
				float x = surface[i].getX();
				float y = surface[i].getZ();

				ps[i].setX(x);
				ps[i].setY(y);
			}

			// 投影
			Polygon2d<Length> polygon(ps);
			delete[] ps;

			return polygon;
		}
	};
}