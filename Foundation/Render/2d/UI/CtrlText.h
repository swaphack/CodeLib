#pragma once

#include "CtrlFrame.h"
#include "Common/struct/protocol_common.h"
#include "Resource/Config/TextDefine.h"
#include "2d/ctrl_common.h"

namespace render
{
	// 2d文本
	/*
		生成在指定区域的文字
		水平对齐方式：左对齐，右对齐， 居中

		在指定框内显示
		垂直对齐方式：顶对齐，底对齐，居中
	*/
	class CtrlText : public CtrlFrame, public TextProtocol
	{
	public:
		CtrlText();
		virtual ~CtrlText();
	public:
		virtual bool init();
		// 设置字库路径
		void setFontPath(const std::string& fonturl);
		// 获取字库路径
		const std::string& getFontPath();
		// 设置字体大小
		void setFontSize(float size);
		// 获取字体大小
		float getFontSize();
		// 设置水平字间距
		void setHorizontalDistance(float distance);
		// 获取水平间距
		float getHorizontalDistance();
		// 设置垂直间距
		void setVerticalDistance(float distance);
		// 获取垂直间距
		float getVerticalDistance();
		// 设置显示的文本
		void setString(const std::string& text);

		// 设置文本水平对齐方式
		void setHorizontalAlignment(HorizontalAlignment alignment);
		// 获取文本水平对齐方式
		HorizontalAlignment getHorizontalAlignment();
		// 设置文本垂直对齐方式
		void setVerticalAlignment(VerticalAlignment alignment);
		// 获取文本垂直对齐方式
		VerticalAlignment getVerticalAlignment();
		// 设置显示区域
		void setDimensions(float width, float height);
		// 设置显示区域
		void setDimensions(const math::Size& size);
		// 获取显示区域
		math::Size getDimensions();
		// 设置颜色
		void setTextColor(const sys::Color3B& color);
		// 颜色
		const sys::Color3B& getTextColor();
	protected:
		math::Vector3 getOrgin(const math::Size& size);
		virtual void onTextChange();
	private:
		// 文本结构
		TextDefine _textDefine;
	};
}