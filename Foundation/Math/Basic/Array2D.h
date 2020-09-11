#pragma once

#include <cstdint>
#include <cstring>
#include <cstdarg>
#include "Array.h"
#include <sstream>
#include "Basic/base.h"

namespace math
{
	/**
	*	二维数组
	*/
	template<typename T, const int Height, const int Width>
	struct Array2D
	{
	public:
		Array2D()
		{
			this->reset();
		}
		Array2D(const T* val)
		{
			this->assign(val);
		}

		Array2D(T start, ...)
		{
			int length = Height * Width;
			T* val = GET_PARAMETERS(length, start);
			this->assign(val);
			free(val);
		}
		Array2D(const Array2D& mat)
		{
			*this = mat;
		}
		virtual ~Array2D()
		{

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
		void setValue(T* array, int len) const
		{
			int length = getLength();
			assert(len <= length);
			memcpy(array, _values, len * sizeof(T));
		}
		/**
		*	列数
		*/
		int getWidth() const
		{
			return Width;
		}
		/**
		*	行数
		*/
		int getHeight() const
		{
			return Height;
		}
		/**
		*	行数
		*/
		int getLength() const
		{
			return Width * Height;
		}
		/**
		*	大小
		*/
		int getSize() const
		{
			return Width * Height * sizeof(T);
		}
		/**
		*	赋值
		*/
		void assign(const T* val)
		{
			assert(val != nullptr);

			memcpy(_values, (T*)val, getSize());
		}
		/**
		*	重置
		*/
		void reset()
		{
			memset(_values, 0, getSize());
		}
		/**
		*	获取指定位置的数据
		*/
		const T& getValue(int index) const
		{
			//printf("%d, %d, %dn", index, Width, Height);
			assert(index >= 0 && index < getLength());

			int i = index / Width;
			int j = index % Width;

			return getValue(i, j);
		}

		/**
		*	获取h行，w列的数据
		*/
		const T& getValue(int i, int j) const
		{
			//printf("Width %d, Height %d, j : %d, i :%dn", Width, Height, j, i);
			assert(i >= 0 && j >= 0 && i < Height && j < Width);

			return _values[i][j];
		}
		/**
		*	设置h行，w列的数据
		*/
		void setValue(int i, int j, const T& value)
		{			
			_values[i][j] = value;
		}
		/**
		*	设置指定位置的数据
		*/
		void setValue(int index, const T& value)
		{
			assert(index >= 0 && index < getLength());

			int i = index / Width;
			int j = index % Width;

			_values[i][j] = value;
		}
	public:
		/**
		*	设置指定行的值
		*/
		void setRow(int row, const Array<T, Width>& value)
		{
			assert(row >= 0 && row < Height);

			assert(value.getLength() == Width);

			for (int i = 0; i < Width; i++)
			{
				setValue(row, i, value.getValue(i));
			}
		}
		/**
		*	设置指定行的值
		*/
		void setRow(int row, const T* value)
		{
			assert(row >= 0 && row < Height);

			for (int i = 0; i < Width; i++)
			{
				setValue(row, i, value[i]);
			}
		}
		/**
		*	获取指定行的值
		*/
		Array<T, Width> getRow(int row) const
		{
			assert(row >= 0 && row < Height);

			Array<T, Width> vector;

			for (int i = 0; i < Width; i++)
			{
				vector.setValue(i, getValue(row, i));
			}

			return vector;
		}
		/**
		*	设置指定列的值
		*/
		void setColumn(int column, const Array<T, Height>& value)
		{
			assert(column >= 0 && column < Width);

			assert(value.getLength() == Height);

			for (int i = 0; i < Height; i++)
			{
				setValue(i, column, value.getValue(i));
			}
		}

		/**
		*	设置指定列的值
		*/
		void setColumn(int column, const T* value)
		{
			assert(column >= 0 && column < Width);

			for (int i = 0; i < Height; i++)
			{
				setValue(i, column, value[i]);
			}
		}
		/**
		*	获取指定列的值
		*/
		Array<T, Height> getColumn(int column) const
		{
			assert(column >= 0 && column < Width);

			Array<T, Height> vector;

			for (int i = 0; i < Height; i++)
			{
				vector.setValue(i, getValue(i, column));
			}

			return vector;
		}
	public:
		/**
		*	获取转置矩阵
		*/
		Array2D transpose() const
		{
			Array2D mat;

			for (int i = 0; i < Height; i++)
			{
				for (int j = 0; j < Width; j++)
				{
					mat.setValue(i, j, getValue(i, j));
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
			int len = mat.Width * mat.Height;
			for (int i = 0; i < len; i++)
			{
				setValue(i, mat.getValue(i));
			}

			return *this;
		}
		/**
		*	获取指定位置的数据
		*/
		T& operator[](int index)
		{
			assert(index >= 0 && index < getLength());

			int i = index / Width;
			int j = index % Width;

			return _values[i][j];
		}
		/**
		*	获取指定位置的数据
		*/
		const T& operator[](int index) const
		{
			assert(index >= 0 && index < getLength());

			int i = index / Width;
			int j = index % Width;

			return _values[i][j];
		}
	public:
		std::string toString() const
		{
			std::ostringstream stream;
			for (int i = 0; i < Height; i++)
			{
				for (int j = 0; j < Width; j++)
				{
					T fValue = getValue(i, j);
					stream << fValue;
					stream << ",";
				}
				stream << "n";
			}

			return stream.str();
		}
	protected:
		T* getPtr()
		{
			return _values;
		}
	protected:
		// 单元值
		T _values[Height][Width];
		// 列数
		//int Width = 0;
		// 行数
		//int Height = 0;
	};
}