#pragma once


namespace math
{
	/**
	*	多元一次线性函数
	*/
	template<typename T, const int Length>
	class MultivariateLinearFunction : public Function
	{
	public:
		MultivariateLinearFunction()
		{
			memset(_values, 0, Length * sizeof(T));
		}
	private:
		T _values[Length];
	};
}