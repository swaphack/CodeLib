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
		MemoryData(size_t length);
		MemoryData(size_t length, const int8_t* value);
		MemoryData(size_t length, const char* value);
		MemoryData(size_t length, const uint8_t* value);
		MemoryData(size_t length, const int8_t* value, uint32_t unitSize);
		MemoryData(const MemoryData& value);
		virtual ~MemoryData();
	public:
		/**
		*	清空
		*/
		void clear();
		/**
		*	大小
		*/
		size_t getSize() const;
		/**
		*	长度
		*/
		size_t getLength() const;
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
		int8_t* getPtr(size_t offset = 0) const;
		/**
		*	指定位置的置
		*/
		int8_t getValue(size_t index) const;
		/**
		*	指定位置的置
		*/
		int8_t& getValue(size_t index);
	public:
		void init(size_t len);
		/**
		*	初始化
		*/
		void init(size_t len, const void* value, uint32_t unitSize);
		/**
		*	初始化
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
		*	长度
		*/
		size_t _length = 0;
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