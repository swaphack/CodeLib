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
	protected:
		// 单元值
		T* _values = nullptr;
		// 列数
		int32_t _width = 0;
		// 行数
		int32_t _height = 0;
	public:
		Array2D()
		{
			this->reset(1, 1);
		}
		Array2D(int32_t h, int32_t w)
		{
			this->reset(h, w);
		}
		Array2D(T* val, int32_t h, int32_t w)
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
		const T* value() const
		{
			return _values;
		}
		/**
		*	列数
		*/
		int32_t getWidth() const
		{
			return _width;
		}
		/**
		*	行数
		*/
		int32_t getHeight() const
		{
			return _height;
		}
		/**
		*	大小
		*/
		int32_t getSize() const
		{
			return _width * _height;
		}
		void set(T* val, int32_t h, int32_t w)
		{
			assert(val != nullptr && w > 0 && h > 0);

			this->dispose();

			_height = h;
			_width = w;
			int size = _width * _height * sizeof(T);
			_values = (T*)malloc(size);
			memset(_values, 0, size);
			memcpy(_values, val, size);
		}
		/**
		*	重置
		*/
		void reset(int32_t h, int32_t w)
		{
			assert(w != 0 && h != 0);

			this->dispose();

			_height = h;
			_width = w;
			int size = _width * _height * sizeof(T);
			_values = (T*)malloc(size);
			memset(_values, 0, size);
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
		const T& getValue(int32_t index) const
		{
			assert(index >= 0 && index < _width * _height);

			return _values[index];
		}

		/**
		*	获取h行，w列的数据
		*/
		const T& getValue(int32_t i, int32_t j) const
		{
			assert(i >= 0 && j >= 0 && i < _height && j < _width);

			return _values[i * _width + j];
		}
		/**
		*	设置h行，w列的数据
		*/
		void setValue(int32_t i, int32_t j, const T& value)
		{
			assert(i >= 0 && j >= 0 && i < _height && j < _width);

			_values[i * _width + j] = value;
		}
		/**
		*	设置指定位置的数据
		*/
		void setValue(int32_t index, const T& value)
		{
			assert(index >= 0 && index < _width * _height);

			_values[index] = value;
		}
	public:
		/**
		*	设置指定行的值
		*/
		void setRow(int32_t row, const Array<T>& value)
		{
			assert(row >= 0 && row < _height);

			assert(value.getSize() == _width);

			for (int32_t i = 0; i < _width; i++)
			{
				_values[row * _width + i] = value.getValue(i);
			}
		}
		/**
		*	获取指定行的值
		*/
		Array<T> getRow(int32_t row)
		{
			assert(row >= 0 && row < _height);

			Array<T> vector(_width);

			for (int32_t i = 0; i < _width; i++)
			{
				vector.setValue(i, _values[row * _width + i]);
			}
		}
		/**
		*	设置指定列的值
		*/
		void setColumn(int32_t column, const Array<T>& value)
		{
			assert(column >= 0 && column < _width);

			assert(value.getSize() == _height);

			for (int32_t i = 0; i < _height; i++)
			{
				_values[i * _height + column] = value.getValue(i);
			}
		}
		/**
		*	获取指定列的值
		*/
		Array<T> getColumn(int32_t column)
		{
			assert(column >= 0 && column < _width);

			Array<T> vector(_height);

			for (int32_t i = 0; i < _height; i++)
			{
				vector.setValue(i, _values[i * _height + column]);
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

			for (int32_t i = 0; i < _height; i++)
			{
				for (int32_t j = 0; j < _width; j++)
				{
					mat.setValue(i * _height + j, _values[i * _width + j]);
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
			this->reset(mat._width, mat._height);
			int32_t len = mat._width * mat._height;
			for (int32_t i = 0; i < len; i++)
			{
				_values[i] = mat[i];
			}

			return *this;
		}
		/**
		*	获取指定位置的数据
		*/
		T& operator[](int32_t index)
		{
			assert(index >= 0 && index < _width * _height);

			return _values[index];
		}
		/**
		*	获取指定位置的数据
		*/
		const T& operator[](int32_t index) const
		{
			assert(index >= 0 && index < _width * _height);
			return _values[index];
		}
	public:
		std::string toString()
		{
			std::ostringstream stream;
			for (int j = 0; j < _height; j++)
			{
				for (int i = 0; i < _width; i++)
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
		}
	};
}