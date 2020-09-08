#pragma once

namespace math
{
	/**
	*	可变长数组
	*/
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
		/**
		*	设置值
		*/
		void set(const T** value)
		{
			if (value == nullptr) return;

			for (int i = 0; i < Length; i++)
			{
				memcpy(_values[i], value[i], sizeof(T) * _length[i]);
			}
		}
		/**
		*	获取值
		*/
		const T& getValue(int i, int j) const
		{
			assert(i >= 0 && i < Length && j >= 0 && j < _length[j]);

			return _values[i][j];
		}
		/**
		*	获取数组
		*/
		const T* getValue(int i)
		{
			assert(i >= 0 && i < Length);

			return _values[i];
		}
		/**
		*	获取值
		*/
		T& getValue(int i, int j)
		{
			assert(i >= 0 && i < Length && j >= 0 && j < _length[j]);

			return _values[i][j];
		}
		/**
		*	设置值
		*/
		void setValue(int i, int j, const T& value)
		{
			assert(i >= 0 && i < Length && j >= 0 && j < _length[j]);

			_values[i][j] = value;
		}
		/**
		*	设置值
		*/
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
