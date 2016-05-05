#pragma once

#include "macros.h"

namespace render
{
	// 2d文本
	class CtrlText : public ColorNode
	{
	public:
		CtrlText();
		virtual ~CtrlText();
	public:
		virtual void draw();
		// 设置字库路径
		void setFontPath(const char* fonturl);
		// 获取字库路径
		const char* getFontPath();
		// 设置字体大小
		void setFontSize(float size);
		// 获取字体大小
		float getFontSize();
		// 设置水平字间距
		void setHorizontalDistance(float distance);
		// 获取垂直间距
		float getHorizontalDistance();
		// 设置水平间距
		void setVerticalDistance(float distance);
		// 获取垂直间距
		float getVerticalDistance();
		// 设置显示的文本
		void setString(const char* text);
		// 获取显示的文本
		const char* getString();

		// 设置水平对齐方式
		void setHorizontalAlignment(HorizontalAlignment alignment);
		// 获取水平对齐方式
		HorizontalAlignment getHorizontalAlignment();
		// 设置垂直对齐方式
		void setVerticalAlignment(VerticalAlignment alignment);
		// 获取垂直对齐方式
		VerticalAlignment getVerticalAlignment();
		// 设置显示区域
		void setDimensions(float width, float height);
		// 获取显示区域
		sys::Size getDimensions();
		// 设置颜色
		void setColor(sys::Color4B color);
		// 获取颜色
		sys::Color4B getColor();
	protected:
		virtual void initSelf();
	private:
		// 文本结构
		Ctrl_TextDefine _textDefine;
		// 纹理帧
		TexFrame* _texFrame;
		// 纹理坐标
		TextureRect _texRect;
	};
}