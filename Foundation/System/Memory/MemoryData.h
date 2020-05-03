#pragma once

#include <cstdint>

namespace sys
{
	/**
	*	�ڴ�����
	*/
	class MemoryData
	{
	public:
		MemoryData();
		MemoryData(size_t length);
		MemoryData(size_t length, const int8_t* value);
		MemoryData(size_t length, const char* value);
		MemoryData(size_t length, const uint8_t* value);
		MemoryData(size_t length, const int8_t* value, uint32_t unitSize);
		MemoryData(const MemoryData& value);
		virtual ~MemoryData();
	public:
		/**
		*	���
		*/
		void clear();
		/**
		*	��С
		*/
		size_t getSize() const;
		/**
		*	����
		*/
		size_t getLength() const;
		/**
		*	����
		*/
		const int8_t* getValue() const;
		/**
		*	��λ��С
		*/
		uint32_t getUnitSize() const;
		/**
		*	ƫ��ָ��
		*/
		int8_t* getPtr(size_t offset = 0) const;
		/**
		*	ָ��λ�õ���
		*/
		int8_t getValue(size_t index) const;
		/**
		*	ָ��λ�õ���
		*/
		int8_t& getValue(size_t index);
	public:
		void init(size_t len);
		/**
		*	��ʼ��
		*/
		void init(size_t len, const void* value, uint32_t unitSize);
		/**
		*	��ʼ��
		*/
		void init(size_t len, const int8_t* value);
		void init(size_t len, const char* value);
		void init(size_t len, const uint8_t* value);
		void init(size_t len, const int16_t* value);
		void init(size_t len, const uint16_t* value);
		void init(size_t len, const int32_t* value);
		void init(size_t len, const uint32_t* value);
		void init(size_t len, const float* value);
		void init(size_t len, const double* value);
	public:
		void set(size_t offset, int size, const int8_t* value);
		void set(size_t offset, int size, const char* value);
		void insert(size_t offset, int size, const int8_t* value);
		void insert(size_t offset, int size, const char* value);
		void remove(size_t offset, int size);

		void resize(size_t len);
	private:
		/**
		*	����
		*/
		size_t _length = 0;
		/**
		*	����
		*/
		int8_t* _value = nullptr;
		/**
		*	��λ
		*/
		uint32_t _uintSize = 1;
	};
}