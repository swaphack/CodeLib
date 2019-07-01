#pragma once

namespace game
{
	/**
	*	ÈýÎ¬×ø±êµã
	*/
	struct Vector
	{
		float X = 0;
		float Y = 0;
		float Z = 0;

		Vector(){}
		Vector(float x, float y, float z) :X(x), Y(y), Z(z){}
		~Vector(){}

		static Vector Zero;
		static Vector One;
	};
}