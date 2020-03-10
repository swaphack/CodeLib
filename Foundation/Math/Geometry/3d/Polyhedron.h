#pragma once

#include <cstdint>
#include "Algebra/import.h"

namespace math
{
	struct Surface;
	/**
	*	������
	*/
	struct Polyhedron
	{
	protected:
		// ��
		Surface* _surfaces = nullptr;
		// ����
		int32_t _count = 0;
	public:
		Polyhedron();
		Polyhedron(Surface* surfaces, int32_t count);
		virtual ~Polyhedron();
	public:
		/**
		*	�Ƿ������
		*	�����������ͶӰ��������
		*/
		bool contiains(const Vector3& point);
		/**
		*	���������Ƿ��ཻ
		*	
		*/
		bool intersects(const Polyhedron& polyhedron);
	};
}