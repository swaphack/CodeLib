#pragma once

#include "Base/Types.h"
#include "StreamBase.h"

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
		void initSteam(ss_t width, ss_t height, ss_t deep = 1);
		// 扩展流，如果有旧数据，旧数据也复制到新流中
		void expendStream(ss_t width, ss_t height, ss_t deep = 1, bool bBottom = false);

		// 从流中读取一组2维数据
		void readBlock(ss_t x, ss_t y, ss_t width, ss_t height, char* outData, ss_t z = 0);
		// 写入一组2维数据到流中
		void writeBlock(ss_t x, ss_t y, ss_t width, ss_t height, const char* inData, ss_t z = 0);
		// 移动内存流
		void moveBlock(ss_t srcX, ss_t srcY, ss_t width, ss_t height, ss_t destX, ss_t destY, ss_t z = 0);

		// 清空内存流数据
		void resetBlock(ss_t x, ss_t y, ss_t width, ss_t height, ss_t z = 0);

		// 从流中读取一组3维数据
		void readBlock(ss_t x, ss_t y, ss_t z, ss_t width, ss_t height, ss_t deep, char* outData);
		// 写入一组3维数据到流中
		void writeBlock(ss_t x, ss_t y, ss_t z, ss_t width, ss_t height, ss_t deep, const char* inData);
		// 移动内存流
		void moveBlock(ss_t x, ss_t y, ss_t z, ss_t width, ss_t height, ss_t deep, ss_t offsetX, ss_t offsetY, ss_t offsetZ);

		// 获取宽度
		inline ss_t getWidth() const { return _width; }
		// 获取高度
		inline ss_t getHeigth() const { return _heigth; }
		// 获取深度
		inline ss_t getDeep() const { return _deep; }
		// 获取数据
		inline const char* getData() const { return _data; }

		void clear();
	protected:
		// 数据
		char* _data;
		// 宽度
		ss_t _width;
		// 高度
		ss_t _heigth;
		// 深度
		ss_t _deep;
	};
}