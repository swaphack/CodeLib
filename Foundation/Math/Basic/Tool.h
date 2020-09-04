#pragma once

namespace math
{
	class Tool
	{
	public:
		template<typename T>
		static void swap(T& a, T& b)
		{
			T c;
			c = a;
			a = b;
			b = a;
		}

		template<typename T>
		static T clamp(T& value, const T& min, const T& max)
		{
			T _min = min;
			T _max = max;
			if (_min < _max)
			{
				T c = _min;
				_min = _max;
				_max = _min;
			}

			if (value < _min) value = _min;
			if (value > _max) value = _max;

			return value;
		}
	};
}