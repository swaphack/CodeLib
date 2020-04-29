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
		MemoryData(uint32_t length);
		MemoryData(uint32_t length, const int8_t* value);
		MemoryData(uint32_t length, const int8_t* value, uint32_t unitSize);
		MemoryData(const MemoryData& value);
		~MemoryData();
	public:
		/**
		*	���
		*/
		void clear();
		/**
		*	��С
		*/
		uint32_t getSize() const;
		/**
		*	����
		*/
		uint32_t getLength() const;
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
		int8_t* getPtr(int offset = 0) const;
	public:
		void init(uint32_t len);
		/**
		*	��ʼ��
		*/
		void init(uint32_t len, const void* value, uint32_t unitSize);
		/**
		*	��ʼ��
		*/
		void init(uint32_t len, const int8_t* value);
		void init(uint32_t len, const char* value);
		void init(uint32_t len, const uint8_t* value);
		void init(uint32_t len, const int16_t* value);
		void init(uint32_t len, const uint16_t* value);
		void init(uint32_t len, const int32_t* value);
		void init(uint32_t len, const uint32_t* value);
		void init(uint32_t len, const float* value);
		void init(uint32_t len, const double* value);
	private:
		/**
		*	����
		*/
		uint32_t _length = 0;
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