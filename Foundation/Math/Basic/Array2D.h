#pragma once

#include <cstdint>
#include <cstring>

#include "Array.h"
#include <sstream>

namespace math
{
	/**
	*	二维数组
	*/
	template<typename T>
	struct Array2D
	{
	public:
		Array2D()
		{
			this->reset(1, 1);
		}
		Array2D(size_t h, size_t w)
		{
			this->reset(h, w);
		}
		Array2D(T* val, size_t h, size_t w)
		{
			this->set(val, h, w);
		}
		Array2D(const Array2D& mat)
		{
			*this = mat;
		}
		virtual ~Array2D()
		{
			this->dispose();
		}
	public:
		/**
		*	单元值
		*/
		const T* getValue() const
		{
			return (T*)_values;
		}
		/**
		*	单元值
		*/
		void getValue(T* array, size_t len) const
		{
			size_t length = _width * _height;
			assert(len <= length);
			memcpy(array, _values, len * sizeof(T));
		}
		/**
		*	列数
		*/
		size_t getWidth() const
		{
			return _width;
		}
		/**
		*	行数
		*/
		size_t getHeight() const
		{
			return _height;
		}
		/**
		*	大小
		*/
		size_t getSize() const
		{
			return _width * _height;
		}
		void set(const T* val, int32_t h, int32_t w)
		{
			assert(val != nullptr && w > 0 && h > 0);

			this->dispose();

			_height = h;
			_width = w;
			int size = _width * _height * sizeof(T);
			uint8_t* values = (uint8_t*)malloc(size);
			memcpy(values, (uint8_t*)val, size);
			_values = values;
		}
		/**
		*	重置
		*/
		void reset(size_t h, size_t w)
		{
			assert(w != 0 && h != 0);

			this->dispose();

			_height = h;
			_width = w;
			int size = _width * _height * sizeof(T);
			uint8_t* values = (uint8_t*)malloc(size);
			memset(values, 0, size);
			_values = values;
		}
		/**
		*	重置
		*/
		void reset()
		{
			if (_values != nullptr && _width != 0 && _height != 0)
			{
				int size = _width * _height * sizeof(T);
				memset(_values, 0, size);
			}
		}
		/**
		*	获取指定位置的数据
		*/
		const T& getValue(size_t index) const
		{
			assert(index >= 0 && index < _width * _height);

			return *(T*)(_values + index * sizeof(T));
		}

		/**
		*	获取h行，w列的数据
		*/
		const T& getValue(size_t i, size_t j) const
		{
			assert(i >= 0 && j >= 0 && i < _height && j < _width);

			int index = i * _width + j;
			return getValue(index);
		}
		/**
		*	设置h行，w列的数据
		*/
		void setValue(size_t i, size_t j, const T& value)
		{
			int index = i * _width + j;
			memcpy(_values + index * sizeof(T), &value, sizeof(T));
		}
		/**
		*	设置指定位置的数据
		*/
		void setValue(size_t index, const T& value)
		{
			assert(index >= 0 && index < _width * _height);

			memcpy(_values + index * sizeof(T), &value, sizeof(T));
		}
	public:
		/**
		*	设置指定行的值
		*/
		void setRow(size_t row, const Array<T>& value)
		{
			assert(row >= 0 && row < _height);

			assert(value.getLength() == _width);

			for (size_t i = 0; i < _width; i++)
			{
				int index = row * _width + i;
				setValue(index, value.getValue(i));
			}
		}
		/**
		*	获取指定行的值
		*/
		Array<T> getRow(size_t row)
		{
			assert(row >= 0 && row < _height);

			Array<T> vector(_width);

			for (size_t i = 0; i < _width; i++)
			{
				vector.setValue(i, getValue(row * _width + i));
			}
		}
		/**
		*	设置指定列的值
		*/
		void setColumn(size_t column, const Array<T>& value)
		{
			assert(column >= 0 && column < _width);

			assert(value.getLength() == _height);

			for (size_t i = 0; i < _height; i++)
			{
				setValue(i * _height + column, value.getValue(i));
			}
		}
		/**
		*	获取指定列的值
		*/
		Array<T> getColumn(size_t column)
		{
			assert(column >= 0 && column < _width);

			Array<T> vector(_height);

			for (size_t i = 0; i < _height; i++)
			{
				vector.setValue(i, getValue(i * _height + column));
			}
		}
	public:
		/**
		*	获取转置矩阵
		*/
		Array2D transpose() const
		{
			Array2D mat;
			mat.reset(_height, _width);

			for (size_t i = 0; i < _height; i++)
			{
				for (size_t j = 0; j < _width; j++)
				{
					mat.setValue(i * _height + j, getValue(i * _width + j));
				}
			}

			return mat;
		}
	public:
		/**
		*	复制矩阵元素
		*/
		Array2D& operator=(const Array2D& mat)
		{
			this->reset(mat._height, mat._width);
			size_t len = mat._width * mat._height;
			for (size_t i = 0; i < len; i++)
			{
				setValue(i, mat.getValue(i));
			}

			return *this;
		}
		/**
		*	获取指定位置的数据
		*/
		T& operator[](size_t index)
		{
			assert(index >= 0 && index < _width * _height);

			return *((T*)(_values + index * sizeof(T)));
		}
		/**
		*	获取指定位置的数据
		*/
		const T& operator[](size_t index) const
		{
			assert(index >= 0 && index < _width * _height);
			return *((T*)(_values + index * sizeof(T)));
		}
	public:
		std::string toString() const
		{
			std::ostringstream stream;
			for (size_t i = 0; i < _height; i++)
			{
				for (size_t j = 0; j < _width; j++)
				{
					T fValue = getValue(i, j);
					stream << fValue;
					stream << ",";
				}
				stream << "\n";
			}

			return stream.str();
		}
	public:
		/**
		*	清除
		*/
		void dispose()
		{
			if (_values)
			{
				free(_values);
				_values = nullptr;
			}
			_width = 0;
			_height = 0;
		}
	protected:
		T* getPtr()
		{
			return (T*)_values;
		}
	private:
		// 单元值
		uint8_t* _values = nullptr;
		// 列数
		size_t _width = 0;
		// 行数
		size_t _height = 0;
	};
}