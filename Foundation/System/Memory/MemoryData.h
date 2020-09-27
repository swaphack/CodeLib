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
		MemoryData(size_t length, const char* value, uint32_t typeSize);
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
		const char* getValue() const;
		/**
		*	��λ��С
		*/
		uint32_t getTypeSize() const;
		/**
		*	ƫ��ָ��
		*/
		char* getPtr(size_t offset = 0) const;
		/**
		*	ָ��λ�õ���
		*/
		char getValue(size_t index) const;
		/**
		*	ָ��λ�õ���
		*/
		char& getValue(size_t index);
	public:
		void init(size_t len);
		void init(size_t len, uint32_t typeSize);
		/**
		*	��ʼ��
		*/
		void init(size_t len, const void* value, uint32_t typeSize);
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
		void set(size_t offset, size_t size, const char* value);
		void reset(size_t offset, size_t size);
		void insert(size_t offset, size_t size, const char* value);
		void remove(size_t offset, size_t size);

		void resize(size_t len, uint32_t typeSize = 1);
	public:
		MemoryData& operator=(const MemoryData& data);
	private:
		/**
		*	����
		*/
		size_t _length = 0;
		/**
		*	����
		*/
		char* _value = nullptr;
		/**
		*	��λ
		*/
		uint32_t _typeSize = 1;
	};
}