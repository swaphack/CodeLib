#pragma once

namespace math
{
	template<typename T, const int Length, int... Sizes>
	class VariableLengthArray
	{
	public:
		VariableLengthArray()
		{
			int* ptr = &Length;
			ptr++;

			_values = new T * [Length];
			for (int i = 0; i < Length; i++)
			{
				int len = ptr[i];
				_length[i] = len;
				_values[i] = new T[len];
			}
		}
		virtual ~VariableLengthArray()
		{
			for (int i = 0; i < Length; i++)
			{
				delete[] _values[i];
			}

			delete[] _values;
		}
	public:
		void set(const T** value)
		{
			if (value == nullptr) return;

			for (int i = 0; i < Length; i++)
			{
				memcpy(_values[i], value[i], sizeof(T) * _length[i]);
			}
		}

		const T& getValue(int i, int j) const
		{
			assert(i >= 0 && i < Length && j >= 0 && j < _length[j]);

			return _values[i][j];
		}

		const T* getValue(int i)
		{
			assert(i >= 0 && i < Length);

			return _values[i];
		}

		T& getValue(int i, int j)
		{
			assert(i >= 0 && i < Length && j >= 0 && j < _length[j]);

			return _values[i][j];
		}

		void setValue(int i, int j, const T& value)
		{
			assert(i >= 0 && i < Length && j >= 0 && j < _length[j]);

			_values[i][j] = value;
		}

		void set(int i, const T* value)
		{
			if (value == nullptr) return;

			memcpy(_values[i], value[i], sizeof(T) * _length[i]);
		}
	private:
		T* _values[Length] = nullptr;

		int _length[Length];
	};
}
