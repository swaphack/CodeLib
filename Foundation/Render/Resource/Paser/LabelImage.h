#pragma once

#include "system.h"
#include "macros.h"

namespace render
{
	// 文本流
	class LabelStream : public sys::MultiStream
	{
	public:
		LabelStream();
		virtual ~LabelStream();
	public:
		// 重置游标
		void resetOffset();

		// 写入开始的位置x
		sys::ss_t getOffsetX() const { return _offsetX; }
		void setOffsetX(sys::ss_t val) { _offsetX = val; }
		// 写入开始的位置y
		sys::ss_t getOffsetY() const { return _offsetY; }
		void setOffsetY(sys::ss_t val) { _offsetY = val; }
		// 行高
		sys::ss_t getLineHeight() const { return _lineHeight; }
		void setLineHeight(sys::ss_t val) { _lineHeight = val; }

		sys::ss_t getLowX() const { return _lowX; }
		void setLowX(sys::ss_t val) { _lowX = val; }

		sys::ss_t getLowY() const { return _lowY; }
		void setLowY(sys::ss_t val) { _lowY = val; }

		sys::ss_t getHeightX() const { return _heightX; }
		void setHeightX(sys::ss_t val) { _heightX = val; }

		sys::ss_t getHeightY() const { return _heightY; }
		void setHeightY(sys::ss_t val) { _heightY = val; }
		// 写入文本流
		void writeLabelBlock(int width, int height, int deltaX, int deltaY, int advY, const char* buffer);
	private:
		// 作为文本调整的参数
		// 最小x
		sys::ss_t _lowX;
		// 最小y
		sys::ss_t _lowY;
		// 最大x
		sys::ss_t _heightX;
		// 最大y
		sys::ss_t _heightY;

		// 写入开始的位置x
		sys::ss_t _offsetX;
		// 写入开始的位置y
		sys::ss_t _offsetY;
		// 行高
		sys::ss_t _lineHeight;
	};

	// 文本图片
	// 文本变成图片，只关心图片的生成，不考虑实际摆放的位置
	class LabelImage : public Image, public ILabelLoader
	{
	public:
		LabelImage();
		virtual ~LabelImage();
	public:
		// 加载文本
		virtual void load(const TextDefine& textDefine);
	private:
		LabelStream* _stream;
	};
}