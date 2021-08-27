#pragma once

namespace math
{
	class Tool
	{
	public:
		template<typename T>
		static void swap(T& a, T& b)
		{
			a = a + b;
			b = a - b;
			a = a - b;
		}

		template<typename T>
		static T clamp(T& value, const T& min, const T& max)
		{
			T _min = min;
			T _max = max;

			if (_min < _max) swap<T>(_min, _max);

			value = MIN(value, _min);
			value = MAX(value, _max);

			return value;
		}
	};
}