#pragma once


#include "macros.h"

#include "Memory/MemoryData.h"

namespace sys
{
	/* 多维数据流
	*
	*	1. 数据存储的方式, 顺序：x->y->z
	*	2.拷贝方式采用先从深度z取面，再在面上取行
	*	先逐行复制， 再逐面复制，实现全部复制
	*
	*
	*	  - - -
	*	/     /|
	*	- - -  | 
	*  |     | /
	*   - - -  
	*	
	*	 y
	*	 | 
	*	 | _ _ x
	*	/
	*  z
	*/
	class MultiStream
	{
	public:
		MultiStream();
		virtual ~MultiStream();
	public:
		// 初始化流
		void initSteam(uint32_t width, uint32_t height, uint32_t depth = 1);
		// 扩展流，如果有旧数据，旧数据也复制到新流中
		void expendStream(uint32_t width, uint32_t height, uint32_t depth = 1, bool bBottom = true);

		// 从流中读取一组2维数据
		void readBlock(uint32_t x, uint32_t y, uint32_t width, uint32_t height, MemoryData& outData, uint32_t z = 0);
		// 写入一组2维数据到流中
		void writeBlock(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* inData, uint32_t z = 0);
		// 写入一组2维数据到流中,y方向翻转
		void writeBlockWithReverseY(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const char* inData, uint32_t z = 0);
		// 移动内存流
		void moveBlock(uint32_t srcX, uint32_t srcY, uint32_t width, uint32_t height, uint32_t destX, uint32_t destY, uint32_t z = 0);

		// 清空内存流数据
		void resetBlock(uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t z = 0);

		// 从流中读取一组3维数据
		void readBlock(uint32_t x, uint32_t y, uint32_t z, uint32_t width, uint32_t height, uint32_t depth, char* outData);
		// 写入一组3维数据到流中
		void writeBlock(uint32_t x, uint32_t y, uint32_t z, uint32_t width, uint32_t height, uint32_t depth, const char* inData);
		// 移动内存流
		void moveBlock(uint32_t x, uint32_t y, uint32_t z, uint32_t width, uint32_t height, uint32_t depth, uint32_t offsetX, uint32_t offsetY, uint32_t offsetZ);

		// 获取宽度
		inline uint32_t getWidth() const { return _width; }
		// 获取高度
		inline uint32_t getHeigth() const { return _heigth; }
		// 获取深度
		inline uint32_t getDepth() const { return _depth; }
		// 获取数据
		inline const char* getData() const { return (char*)_data.getValue(); }

		void clear();
	protected:
		// 数据
		MemoryData _data;
		// 宽度
		uint32_t _width = 0;
		// 高度
		uint32_t _heigth = 0;
		// 深度
		uint32_t _depth = 0;
	};
}