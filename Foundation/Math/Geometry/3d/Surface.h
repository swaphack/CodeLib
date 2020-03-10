#pragma once

#include <cstdlib>
#include "Algebra/import.h"

namespace math
{
	struct Polygon;
	/**
	*	���弸�ε���
	*/
	struct Surface
	{
	protected:
		Vector3* _points = nullptr;
		int32_t _count = 0;
	public:
		Surface();
		Surface(const Surface& surface);
		Surface(Vector3* poins, int32_t count);

		virtual ~Surface();
	public:
		/**
		*	������
		*/
		Vector3 normalVector() const;
		/**
		*	�Ƿ������
		*	���ж��Ƿ��棬���ж�ͶӰ�Ƿ����
		*/
		bool contains(const Vector3& point);
		/**
		*	����=
		*/
		Surface& operator=(const Surface& surface);
	public:
		/**
		*	�Ƿ��Ǳ�׼�Ķ���Σ����������ڵ���3,�������ڲ����ڹ��ߵ����
		*	�ҹ���
		*/
		static bool isStandard(const Surface& surface);
		/**
		*	�Ƿ���͹�����
		*/
		static bool isConvex(const Surface& surface);
		/**
		*	����ƽ���Ƿ���
		*/
		static bool isCoplanar(const Surface& surface, const Vector3& point);
		/**
		*	�ĵ��Ƿ���
		*/
		static bool isCoplanar(const Vector3& point0, const Vector3& point1, const Vector3& point2, 
			const Vector3& point3);
		/**
		*	ͶӰ��xoy��
		*/
		static Polygon projectOnXOY(const Surface& surface);
		/**
		*	ͶӰ��yoz��
		*/
		static Polygon projectOnYOZ(const Surface& surface);
		/**
		*	ͶӰ��xoz��
		*/
		static Polygon projectOnXOZ(const Surface& surface);
	};
}