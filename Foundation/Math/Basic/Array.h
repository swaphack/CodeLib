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
	// 创建轴
#define CREATE_INDEX_VALUE(Name, Index, Type)\
	public: \
	Type get##Name() const { return (Type)getValue(Index); }\
	void set##Name(Type val) { setValue(Index, val); }

	/**
	*	一维数组
	*/
	template<typename T, const int Length>
	struct Array
	{
	public:
		Array()
		{
			reset();
		}
		Array(T* val)
		{
			this->set(val);
		}
		Array(const Array& vec)
		{
			*this = vec;
		}
		virtual ~Array()
		{
		}
	public:
		/**
		*	单元值
		*/
		const T* getValue() const
		{
			return _values;
		}
		/**
		*	单元值
		*/
		void setValue(T* array) const
		{
			memcpy(array, _values, getSize());
		}
		/**
		*	向量长度
		*/
		int getLength() const
		{
			return Length;
		}
		/**
		*	向量大小
		*/
		int getSize() const
		{
			return getLength() * sizeof(T);
		}
	public:
		/**
		*	设置值
		*/
		void set(const T* val)
		{
			if (val == nullptr)
			{
				return;
			}

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
			assert(index >= 0 && index < Length);

			return _values[index];
		}
		/**
		*	设置指定位置的数据
		*/
		void setValue(int index, const T& value)
		{
			assert(index >= 0 && index < Length);

			_values[index] = value;
		}
		/**
		*	获取指定位置的数据
		*/
		T& operator[](int index)
		{
			assert(index >= 0 && index < Length);

			return _values[index];
		}
		/**
		*	获取指定位置的数据
		*/
		const T& operator[](int index) const
		{
			assert(index >= 0 && index < Length);

			return _values[index];
		}
	public:
		/**
		*	复制元素
		*/
		Array& operator=(const Array& vec)
		{
			int count = vec.getLength();

			for (int i = 0; i < count; i++)
			{
				 setValue(i, vec.getValue(i));
			}

			return *this;
		}
		/**
		*	相乘
		*/
		float operator*(const Array& vec)
		{
			float value = 0;
			for (int i = 0; i < Length; i++)
			{
				value += this->getValue(i) * vec.getValue(i);
			}

			return value;
		}

		std::string toString() const
		{
			std::ostringstream stream;
			for (int i = 0; i < Length; i++)
			{
				const T& fValue = getValue(i);
				stream << fValue;
				stream << ",";
			}

			return stream.str();
		}
	protected:
		T* getPtr()
		{
			return _values;
		}
	private:
		/**
		*	单元值
		*/
		T _values[Length];
	};
}