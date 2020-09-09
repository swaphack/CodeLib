#pragma once

#include <cstdlib>
#include "Algebra/import.h"

namespace math
{
	/**
	*	���弸�ε���
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
		*	������
		*/
		Vector3 normalVector() const
		{
			Vector3 v0 = (*this)[1] - (*this)[0];
			Vector3 v1 = (*this)[2] - (*this)[1];

			return Vector3::cross(v0, v1);
		}
		/**
		*	�Ƿ������
		*	���ж��Ƿ��棬���ж�ͶӰ�Ƿ����
		*/
		bool contains(const Vector3& point)
		{
			if (!isCoplanar(*this, point))
			{ // ������
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
		*	����=
		*/
		Surface3d& operator=(const Surface3d& surface)
		{
			this->assign(surface.getValue());
		}
	public:
		/**
		*	�Ƿ��Ǳ�׼�Ķ���Σ����������ڵ���3,�������ڲ����ڹ��ߵ����
		*	�ҹ���
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
				// �ڱߵ�����
				Vector3 l0 = surface[(i + 1) % lineCount] - surface[i % lineCount];
				Vector3 l1 = surface[(i + 2) % lineCount] - surface[(i + 1) % lineCount];
				Vector3 l2 = surface[(i + 3) % lineCount] - surface[(i + 2) % lineCount];
				// ����������ƽ��ķ�����
				Vector3 n0 = Vector3::cross(l0, l1);
				Vector3 n1 = Vector3::cross(l1, l2);
				if (Vector3::dot(n0, n1) != 0)
				{ // ������������
					return false;
				}
				if (n0.getX() * n1.getX() < 0)
				{// ��������ͬ��
					return false;
				}
			}

			return true;
		}
		/**
		*	�Ƿ���͹�����
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
		*	����ƽ���Ƿ���
		*/
		static bool isCoplanar(const Surface3d& surface, const Vector3& point)
		{
			if (!isStandard(surface))
			{
				return false;
			}
			int32_t lineCount = surface.getLength();
			// �ڱߵ�����
			Vector3 l0 = surface[1] - surface[0];
			Vector3 l1 = surface[2] - surface[1];
			Vector3 l2 = point - surface[2];
			// ������
			Vector3 n0 = Vector3::cross(l0, l1);
			Vector3 n1 = Vector3::cross(l1, l2);
			if (Vector3::dot(n0, n1) != 0)
			{ // ������������
				return false;
			}
			if (n0.getX() * n1.getX() < 0)
			{// ��������ͬ��
				return false;
			}

			return true;
		}
		/**
		*	�ĵ��Ƿ���
		*/
		static bool canMakeCoplanar(const Vector3& point0, const Vector3& point1, const Vector3& point2,
			const Vector3& point3)
		{
			// �ڱߵ�����
			Vector3 l0 = point1 - point0;
			Vector3 l1 = point2 - point1;
			Vector3 l2 = point3 - point2;

			if (Vector3::isThreePointsOnSameLine(point0, point1, point2))
			{ // ���ڹ��ߣ����ɲ���ƽ��
				return false;
			}

			// ������
			Vector3 n0 = Vector3::cross(l0, l1);
			Vector3 n1 = Vector3::cross(l1, l2);
			if (Vector3::dot(n0, n1) != 0)
			{ // ������������
				return false;
			}
			if (n0.getX() * n1.getX() < 0)
			{// ��������ͬ��
				return false;
			}

			return true;
		}
		/**
		*	ͶӰ��xoy��
		*/
		static Polygon2d<Length> projectOnXOY(const Surface3d& surface)
		{
			int32_t count = surface.getLength();
			// ͶӰ�������
			Vector2* ps = new Vector2[count];
			for (int32_t i = 0; i < count; i++)
			{
				float x = surface[i].getX();
				float y = surface[i].getY();
				ps[i].setX(x);
				ps[i].setY(y);
			}

			// ͶӰ
			Polygon2d<Length> polygon(ps);
			delete[] ps;

			return polygon;
		}
		/**
		*	ͶӰ��yoz��
		*/
		static Polygon2d<Length> projectOnYOZ(const Surface3d& surface)
		{
			int32_t count = surface.getLength();
			// ͶӰ�������
			Vector2* ps = new Vector2[count];
			for (int32_t i = 0; i < count; i++)
			{
				float x = surface[i].getX();
				float y = surface[i].getY();
				ps[i].setX(x);
				ps[i].setY(y);
			}

			// ͶӰ
			Polygon2d<Length> polygon(ps);
			delete[] ps;

			return polygon;
		}
		/**
		*	ͶӰ��xoz��
		*/
		static Polygon2d<Length> projectOnXOZ(const Surface3d& surface)
		{
			int32_t count = surface.getLength();
			// ͶӰ�������
			Vector2* ps = new Vector2[count];
			for (int32_t i = 0; i < count; i++)
			{
				float x = surface[i].getX();
				float y = surface[i].getZ();

				ps[i].setX(x);
				ps[i].setY(y);
			}

			// ͶӰ
			Polygon2d<Length> polygon(ps);
			delete[] ps;

			return polygon;
		}
	};
}