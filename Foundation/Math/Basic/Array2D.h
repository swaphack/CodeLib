#pragma once

#include <cstdint>
#include <cstring>

#include "Array.h"
#include <sstream>

namespace math
{
	/**
	*	��ά����
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
		*	��Ԫֵ
		*/
		const T* getValue() const
		{
			return (T*)_values;
		}
		/**
		*	��Ԫֵ
		*/
		void getValue(T* array, size_t len) const
		{
			size_t length = _width * _height;
			assert(len <= length);
			memcpy(array, _values, len * sizeof(T));
		}
		/**
		*	����
		*/
		size_t getWidth() const
		{
			return _width;
		}
		/**
		*	����
		*/
		size_t getHeight() const
		{
			return _height;
		}
		/**
		*	��С
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
		*	����
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
		*	����
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
		*	��ȡָ��λ�õ�����
		*/
		const T& getValue(size_t index) const
		{
			assert(index >= 0 && index < _width * _height);

			return *(T*)(_values + index * sizeof(T));
		}

		/**
		*	��ȡh�У�w�е�����
		*/
		const T& getValue(size_t i, size_t j) const
		{
			assert(i >= 0 && j >= 0 && i < _height && j < _width);

			int index = i * _width + j;
			return getValue(index);
		}
		/**
		*	����h�У�w�е�����
		*/
		void setValue(size_t i, size_t j, const T& value)
		{
			int index = i * _width + j;
			memcpy(_values + index * sizeof(T), &value, sizeof(T));
		}
		/**
		*	����ָ��λ�õ�����
		*/
		void setValue(size_t index, const T& value)
		{
			assert(index >= 0 && index < _width * _height);

			memcpy(_values + index * sizeof(T), &value, sizeof(T));
		}
	public:
		/**
		*	����ָ���е�ֵ
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
		*	��ȡָ���е�ֵ
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
		*	����ָ���е�ֵ
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
		*	��ȡָ���е�ֵ
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
		*	��ȡת�þ���
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
		*	���ƾ���Ԫ��
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
		*	��ȡָ��λ�õ�����
		*/
		T& operator[](size_t index)
		{
			assert(index >= 0 && index < _width * _height);

			return *((T*)(_values + index * sizeof(T)));
		}
		/**
		*	��ȡָ��λ�õ�����
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
		*	���
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
		// ��Ԫֵ
		uint8_t* _values = nullptr;
		// ����
		size_t _width = 0;
		// ����
		size_t _height = 0;
	};
}