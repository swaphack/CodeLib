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
	// ������
#define CREATE_INDEX_VALUE(Name, Index, Type)\
	public: \
	Type get##Name() const { return (Type)getValue(Index); }\
	void set##Name(Type val) { setValue(Index, val); }

	/**
	*	һά����
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
		*	��Ԫֵ
		*/
		const T* getValue() const
		{
			return _values;
		}
		/**
		*	��Ԫֵ
		*/
		void setValue(T* array) const
		{
			memcpy(array, _values, getSize());
		}
		/**
		*	��������
		*/
		int getLength() const
		{
			return Length;
		}
		/**
		*	������С
		*/
		int getSize() const
		{
			return getLength() * sizeof(T);
		}
	public:
		/**
		*	����ֵ
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
		*	����
		*/
		void reset()
		{
			memset(_values, 0, getSize());
		}
		/**
		*	��ȡָ��λ�õ�����
		*/
		const T& getValue(int index) const
		{
			assert(index >= 0 && index < Length);

			return _values[index];
		}
		/**
		*	����ָ��λ�õ�����
		*/
		void setValue(int index, const T& value)
		{
			assert(index >= 0 && index < Length);

			_values[index] = value;
		}
		/**
		*	��ȡָ��λ�õ�����
		*/
		T& operator[](int index)
		{
			assert(index >= 0 && index < Length);

			return _values[index];
		}
		/**
		*	��ȡָ��λ�õ�����
		*/
		const T& operator[](int index) const
		{
			assert(index >= 0 && index < Length);

			return _values[index];
		}
	public:
		/**
		*	����Ԫ��
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
		*	���
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
		*	��Ԫֵ
		*/
		T _values[Length];
	};
}