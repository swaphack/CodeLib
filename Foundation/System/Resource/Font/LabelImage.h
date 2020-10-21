#pragma once

#include "Stream/MultiStream.h"
#include "TextDefine.h"
#include "ILabelLoader.h"
#include "../Image/ImageDetail.h"
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

		void setFixWidth(uint32_t width);
		uint32_t getFixWidth();
		// 固定宽度
		bool isFixWidth();

		// 行高
		uint32_t getLineHeight() const;
		void setLineHeight(uint32_t val);

		// 写入当行文本
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
		int32_t _offsetX;
		// 写入开始的位置y
		int32_t _offsetY;
		// 行高
		uint32_t _lineHeight;
		// 固定宽度
		uint32_t _fixWidth;

		std::stack<int> _lineWidthStack;
	};

	// 文本图片
	// 文本变成图片，只关心图片的生成，不考虑实际摆放的位置
	class LabelImage : public ImageDetail, public ILabelLoader
	{
	public:
		LabelImage();
		virtual ~LabelImage();
	public:
		// 加载文本
		virtual bool load(const TextDefine& textDefine);
	private:
		LabelStream* _stream;
	};
}