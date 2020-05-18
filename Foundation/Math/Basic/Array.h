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
	public:
		Array()
		{
		}
		Array(size_t len)
		{
			this->reset(len);
		}
		Array(T* val, size_t len)
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
		const T* getValue() const
		{
			return (T*)_values;
		}
		/**
		*	单元值
		*/
		void getValue(T* array, size_t len) const
		{
			assert(len <= _length);
			memcpy(array, _values, len * sizeof(T));
		}
		/**
		*	向量长度
		*/
		size_t getLength() const
		{
			return _length;
		}
		/**
		*	向量大小
		*/
		size_t getSize() const
		{
			return getLength() * sizeof(T);
		}
	public:
		/**
		*	重置
		*/
		void reset(size_t len)
		{
			this->dispose();

			_length = len;
			size_t size = _length * sizeof(T);
			uint8_t* values = (uint8_t*)malloc(size);
			memset(values, 0, size);
			_values = values;
		}
		/**
		*	设置值
		*/
		void set(const T* val, size_t len)
		{
			if (val == nullptr)
			{
				return;
			}
			this->dispose();

			_length = len;
			size_t size = _length * sizeof(T);
			uint8_t* values = (uint8_t*)malloc(size);
			memset(values, 0, size);
			memcpy(values, (uint8_t*)val, size);
			_values = values;
			_values = values;
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
		const T& getValue(size_t index) const
		{
			assert(index >= 0 && index < _length);

			return *(T*)(_values + index * sizeof(T));
		}
		/**
		*	设置指定位置的数据
		*/
		void setValue(size_t index, const T& value)
		{
			assert(index >= 0 && index < _length);

			memcpy(_values + index * sizeof(T), &value, sizeof(T));
		}
		/**
		*	获取指定位置的数据
		*/
		T& operator[](size_t index)
		{
			assert(index >= 0 && index < _length);

			return *((T*)(_values + index * sizeof(T)));
		}
		/**
		*	获取指定位置的数据
		*/
		const T& operator[](size_t index) const
		{
			assert(index >= 0 && index < _length);

			return *((T*)(_values + index * sizeof(T)));
		}
	public:
		/**
		*	复制元素
		*/
		Array& operator=(const Array& vec)
		{
			int count = vec.getLength();
			this->dispose();
			this->reset(count);

			for (int i = 0; i < count; i++)
			{
				 setValue(i, vec.getValue(i));
			}

			return *this;
		}

		std::string toString() const
		{
			std::ostringstream stream;
			for (int i = 0; i < _length; i++)
			{
				const T& fValue = getValue(i);
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
	protected:
		T* getPtr()
		{
			return (T*)_values;
		}
	private:
		/**
		*	单元值
		*/
		uint8_t* _values = nullptr;
		/**
		*	向量长度
		*/
		size_t _length = 0;
	};
}