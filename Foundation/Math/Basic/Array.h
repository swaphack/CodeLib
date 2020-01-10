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
	*	一维数组
	*/
	template<typename T>
	struct Array
	{
	protected:
		/**
		*	单元值
		*/
		T* _values = nullptr;
		/**
		*	向量长度
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
		*	单元值
		*/
		const T* value() const
		{
			return _values;
		}
		/**
		*	向量长度
		*/
		int32_t getSize() const
		{
			return _length;
		}
	public:
		/**
		*	重置
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
		*	设置值
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
		*	重置
		*/
		void reset()
		{
			assert(_length > 0);

			this->reset(_length);
		}
		/**
		*	获取指定位置的数据
		*/
		T getValue(int32_t index) const
		{
			assert(index >= 0 && index < _length);

			return _values[index];
		}
		/**
		*	设置指定位置的数据
		*/
		void setValue(int32_t index, T value)
		{
			assert(index >= 0 && index < _length);

			_values[index] = value;
		}
		/**
		*	获取指定位置的数据
		*/
		T& operator[](int32_t index)
		{
			assert(index >= 0 && index < _length);

			return _values[index];
		}
		/**
		*	获取指定位置的数据
		*/
		const T& operator[](int32_t index) const
		{
			assert(index >= 0 && index < _length);

			return _values[index];
		}
	public:
		/**
		*	复制元素
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
		*	清除
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