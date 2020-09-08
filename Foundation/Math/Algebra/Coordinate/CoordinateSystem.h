#pragma once

namespace math
{
	/**
	*	×ø±êÏµ
	*/
	template<const int Count>
	class CoordinateSystem
	{
	public:
		CoordinateSystem();
		virtual ~CoordinateSystem();
	protected:
	private:
		SquareMatrix<Count>;
	};
}