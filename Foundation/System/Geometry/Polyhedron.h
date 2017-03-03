#pragma once

namespace sys
{
	/**
	*	������
	*/
	struct Polyhedron
	{
		/**
		*	���������Ƿ��ཻ
		*/
		bool intersects(const Polyhedron& polyhedron);
	public:
		/**
		*	ͶӰ��xoy��
		*/
		static Polygon projectOnXOY(const Polyhedron& surface);
		/**
		*	ͶӰ��yoz��
		*/
		static Polygon projectOnYOZ(const Polyhedron& surface);
		/**
		*	ͶӰ��xoz��
		*/
		static Polygon projectOnXOZ(const Polyhedron& surface);
	};
}