#pragma once

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
		int count;
		
		Polyhedron();
		Polyhedron(Surface* surfaces, int count);
		~Polyhedron();

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