#pragma once
#include "macros.h"

namespace sys
{
	struct Surface;
	/**
	*	������
	*/
	struct Polyhedron
	{
		// ��
		Surface* surfaces;
		// ����
		int32 count;
		
		Polyhedron();
		Polyhedron(Surface* surfaces, int32 count);
		~Polyhedron();

		/**
		*	�Ƿ������
		*	�����������ͶӰ��������
		*/
		bool contiains(const Vector3& point32);
		/**
		*	���������Ƿ��ཻ
		*	
		*/
		bool int32ersects(const Polyhedron& polyhedron);
	};
}