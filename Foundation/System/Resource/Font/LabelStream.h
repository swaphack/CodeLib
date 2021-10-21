#pragma once

#include "Stream/MultiStream.h"
#include "TextDefine.h"
#include <stack>

namespace sys
{
	/**
	*	文本流
	*
	*
	*		  _ _ x
	*		/|
	*	 z / |
	*		 y
	*/
	class LabelStream : public MultiStream
	{
	public:
		LabelStream();
		virtual ~LabelStream();
	public:
		// 重置游标
		void resetOffset();
		// 固定宽度
		void setFixedWidth(uint32_t width);
		uint32_t getFixedWidth();

		// 固定宽度
		void setFixedHeight(uint32_t height);
		uint32_t getFixedHeight();

		// 固定宽度
		bool isFixedWidth();
		// 固定宽度
		bool isFixedHeight();
		// 行高
		uint32_t getLineHeight() const;
		void setLineHeight(uint32_t val);

		// 写入单行文本
		void writeOneLineBlock(int width, int height, const char* buffer, int deltaY);
		// 写入多行文本
		void writeMultiLineBlock(int width, int height, const char* buffer, int deltaY);
		// 换行
		void writeEndLine();
		// 空一行
		void writeSpaceLine();
		// 结束流写入
		void endStream();
		// 处理水平对齐方式
		void format(HorizontalAlignment ha);
	private:
		// 写入开始的位置x
		int32_t _offsetX = 0;
		// 写入开始的位置y
		int32_t _offsetY = 0;
		// 行高
		uint32_t _lineHeight = 0;
		// 固定宽度
		uint32_t _fixedWidth = 0;
		// 固定高度
		uint32_t _fixedHeight = 0;
		// 横坐标宽偏移
		std::stack<int> _lineWidthStack;
	};
}
