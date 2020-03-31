#pragma once

#include <string>
#include <cstdint>
#include <queue>

namespace sys
{
	struct NetData
	{
	public:
		// 数据
		char* data;
		// 大小
		int32_t size;
		// 游标
		int32_t pos;
	public:
		NetData();
		NetData(const std::string& value);
		NetData(const char* value, int32_t size);
		~NetData();
	public:
		/**
		*	当前指针位置
		*/
		const char* getCursorPtr();
		/**
		*	剩余未读取空间大小
		*/
		int32_t getRemainSize();
		/**
		*	初始化
		*/
		void init(const char* value, int32_t len);
		/**
		*	在头部插入
		*/
		void insert(const char* data, int32_t len);
	};
}