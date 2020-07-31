#pragma once


namespace math
{
	/**
	*	��Ԫһ�����Ժ���
	*/
	template<typename T, const int Length>
	class MultivariateLinearFunction : public Function
	{
	public:
		Function()
		{
			memset(_values, 0, Length * sizeof(T));
		}
	private:
		T _values[Length];
	};
}