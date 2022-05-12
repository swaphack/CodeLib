#pragma once

#include <string>
#include <cstdint>
#include <queue>

#include "Memory/MemoryData.h"

namespace sys
{
	struct NetData
	{
	public:
		// 数据
		MemoryData data;
		// 游标
		int32_t pos = 0;
	public:
		NetData();
		NetData(const std::string& value);
		NetData(const char* value, int32_t size);
		NetData(const NetData& value);
		NetData(const MemoryData& value);
		~NetData();
	public:
		/**
		*	当前指针位置
		*/
		const char* getPtr() const;
		/**
		*	大小
		*/
		uint32_t getSize() const;
		/**
		*	当前指针位置
		*/
		const char* getCursorPtr() const;
		/**
		*	剩余未读取空间大小
		*/
		int32_t getRemainSize() const;
	public:
		/**
		*	重置位置，从0开始
		*/
		void resetPos();
		/**
		*	初始化
		*/
		void init(const char* value, int32_t len);
		/**
		*	在尾部插入
		*/
		void append(const char* value, int32_t len);
	};
}