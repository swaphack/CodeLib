#pragma once

namespace math
{
	/**
	*	����ϵ
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