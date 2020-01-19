#pragma once

#include "macros.h"

namespace render
{
	/**
	*	ø’º‰ Ù–‘
	*/
	class DCSpace : public DrawCommand
	{
	public:
		bool Relative;
		math::Vector3 Position;
		math::Vector3 Scale;
		math::Vector3 Rotation;
	public:
		DCSpace();
		virtual ~DCSpace();
	public:
		virtual void draw();
	public:
		static DCSpace* create(const math::Vector3& position, const math::Vector3& scale, const math::Vector3& rotation, bool relative);
	};

	class DCSpaceMatrix : public DrawCommand
	{
	public:
		bool Relative;
		math::Matrix Matrix;
	public:
		DCSpaceMatrix();
		virtual ~DCSpaceMatrix();
	public:
		virtual void draw();
	public:
		static DCSpaceMatrix* create(const math::Matrix& matrix, bool relative);
	};
}