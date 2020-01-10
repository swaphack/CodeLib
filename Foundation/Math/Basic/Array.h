#pragma once

#include <cstdint>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <sstream>

namespace math
{
	/**
	*	һά����
	*/
	template<typename T>
	struct Array
	{
	protected:
		/**
		*	��Ԫֵ
		*/
		T* _values = nullptr;
		/**
		*	��������
		*/
		int32_t _length = 0;
	public:
		Array()
		{
		}
		Array(int32_t len)
		{
			this->reset(len);
		}
		Array(T* val, int32_t len)
		{
			this->set(val, len);
		}
		Array(const Array& vec)
		{
			*this = vec;
		}
		virtual ~Array()
		{
			this->dispose();
		}
	public:
		/**
		*	��Ԫֵ
		*/
		const T* value() const
		{
			return _values;
		}
		/**
		*	��������
		*/
		int32_t getSize() const
		{
			return _length;
		}
	public:
		/**
		*	����
		*/
		void reset(int32_t len)
		{
			this->dispose();

			_length = len;
			int32_t size = _length * sizeof(T);
			_values = (T*)malloc(size);
			memset(_values, 0, size);
		}
		/**
		*	����ֵ
		*/
		void set(T* val, int32_t len)
		{
			if (val == nullptr)
			{
				return;
			}
			this->dispose();
			this->reset(len);

			for (int i = 0; i < len; i++)
			{
				_values[i] = val[i];
			}
		}
		/**
		*	����
		*/
		void reset()
		{
			assert(_length > 0);

			this->reset(_length);
		}
		/**
		*	��ȡָ��λ�õ�����
		*/
		T getValue(int32_t index) const
		{
			assert(index >= 0 && index < _length);

			return _values[index];
		}
		/**
		*	����ָ��λ�õ�����
		*/
		void setValue(int32_t index, T value)
		{
			assert(index >= 0 && index < _length);

			_values[index] = value;
		}
		/**
		*	��ȡָ��λ�õ�����
		*/
		T& operator[](int32_t index)
		{
			assert(index >= 0 && index < _length);

			return _values[index];
		}
		/**
		*	��ȡָ��λ�õ�����
		*/
		const T& operator[](int32_t index) const
		{
			assert(index >= 0 && index < _length);

			return _values[index];
		}
	public:
		/**
		*	����Ԫ��
		*/
		Array& operator=(const Array& vec)
		{
			int count = vec.getSize();
			this->dispose();
			this->reset(count);

			for (int i = 0; i < count; i++)
			{
				_values[i] = vec[i];
			}

			return *this;
		}

		std::string toString()
		{
			std::ostringstream stream;
			for (int j = 0; j < _height; j++)
			{
				T fValue = getValue(i, j);
				stream << fValue;
				stream << ",";
			}

			return stream.str();
		}
	protected:
		/**
		*	���
		*/
		void dispose()
		{
			if (_values != nullptr)
			{
				free(_values);
				_values = nullptr;
			}
			_length = 0;
		}
	};
}