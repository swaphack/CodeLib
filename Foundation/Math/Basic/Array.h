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
			assert(len <= _length);
			memcpy(array, _values, len * sizeof(T));
		}
		/**
		*	��������
		*/
		size_t getLength() const
		{
			return _length;
		}
		/**
		*	������С
		*/
		size_t getSize() const
		{
			return getLength() * sizeof(T);
		}
	public:
		/**
		*	����
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
		*	����ֵ
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
		const T& getValue(size_t index) const
		{
			assert(index >= 0 && index < _length);

			return *(T*)(_values + index * sizeof(T));
		}
		/**
		*	����ָ��λ�õ�����
		*/
		void setValue(size_t index, const T& value)
		{
			assert(index >= 0 && index < _length);

			memcpy(_values + index * sizeof(T), &value, sizeof(T));
		}
		/**
		*	��ȡָ��λ�õ�����
		*/
		T& operator[](size_t index)
		{
			assert(index >= 0 && index < _length);

			return *((T*)(_values + index * sizeof(T)));
		}
		/**
		*	��ȡָ��λ�õ�����
		*/
		const T& operator[](size_t index) const
		{
			assert(index >= 0 && index < _length);

			return *((T*)(_values + index * sizeof(T)));
		}
	public:
		/**
		*	����Ԫ��
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
	protected:
		T* getPtr()
		{
			return (T*)_values;
		}
	private:
		/**
		*	��Ԫֵ
		*/
		uint8_t* _values = nullptr;
		/**
		*	��������
		*/
		size_t _length = 0;
	};
}