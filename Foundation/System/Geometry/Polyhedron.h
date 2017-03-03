#pragma once

namespace sys
{
	/**
	*	多面体
	*/
	struct Polyhedron
	{
		/**
		*	两多面体是否相交
		*/
		bool intersects(const Polyhedron& polyhedron);
	public:
		/**
		*	投影到xoy面
		*/
		static Polygon projectOnXOY(const Polyhedron& surface);
		/**
		*	投影到yoz面
		*/
		static Polygon projectOnYOZ(const Polyhedron& surface);
		/**
		*	投影到xoz面
		*/
		static Polygon projectOnXOZ(const Polyhedron& surface);
	};
}