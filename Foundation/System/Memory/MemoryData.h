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
		MemoryData(size_t length, const char* value, uint32_t typeSize);
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
		const char* getValue() const;
		/**
		*	单位大小
		*/
		uint32_t getTypeSize() const;
		/**
		*	偏移指针
		*/
		char* getPtr(size_t offset = 0) const;
		/**
		*	指定位置的置
		*/
		char getValue(size_t index) const;
		/**
		*	指定位置的置
		*/
		char& getValue(size_t index);
	public:
		void init(size_t len);
		void init(size_t len, uint32_t typeSize);
		/**
		*	初始化
		*/
		void init(size_t len, const void* value, uint32_t typeSize);
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
		void set(size_t offset, size_t size, const char* value);
		void reset(size_t offset, size_t size);
		void insert(size_t offset, size_t size, const char* value);
		void remove(size_t offset, size_t size);

		void resize(size_t len, uint32_t typeSize = 1);
	public:
		MemoryData& operator=(const MemoryData& data);
	private:
		/**
		*	长度
		*/
		size_t _length = 0;
		/**
		*	数据
		*/
		char* _value = nullptr;
		/**
		*	单位
		*/
		uint32_t _typeSize = 1;
	};
}