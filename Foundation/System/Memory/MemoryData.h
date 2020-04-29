#pragma once

#include <cstdint>

namespace sys
{
	/**
	*	内存数据
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
		*	清空
		*/
		void clear();
		/**
		*	大小
		*/
		uint32_t getSize() const;
		/**
		*	长度
		*/
		uint32_t getLength() const;
		/**
		*	数据
		*/
		const int8_t* getValue() const;
		/**
		*	单位大小
		*/
		uint32_t getUnitSize() const;
		/**
		*	偏移指针
		*/
		int8_t* getPtr(int offset = 0) const;
	public:
		void init(uint32_t len);
		/**
		*	初始化
		*/
		void init(uint32_t len, const void* value, uint32_t unitSize);
		/**
		*	初始化
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
		*	长度
		*/
		uint32_t _length = 0;
		/**
		*	数据
		*/
		int8_t* _value = nullptr;
		/**
		*	单位
		*/
		uint32_t _uintSize = 1;
	};
}