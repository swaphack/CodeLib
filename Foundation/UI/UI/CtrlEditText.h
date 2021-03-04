#pragma once

#include "CtrlEditBox.h"
#include "TextProtocol.h"
#include "physicslib.h"

namespace ui
{
	class CtrlText;
	class CtrlImage;

	// 可编辑文本
	class CtrlEditText : public CtrlEditBox, public TextProtocol
	{
	public:
		CtrlEditText();
		virtual ~CtrlEditText();
	public:
		virtual bool init();
	public:
		/**
		*	设置文本
		*/ 
		virtual void setString(const std::string& text);
		/**
		*	获取显示文本控件
		*/ 
		CtrlText* getTextControl() const;
		/**
		*	设置字库路径
		*/
		void setFontPath(const std::string& fonturl);
		/**
		*	获取字库路径
		*/
		const std::string& getFontPath()  const;
		/**
		*	设置字体大小
		*/
		void setFontSize(float size);
		/**
		*	获取字体大小
		*/
		float getFontSize()  const;
		/**
		*	设置颜色
		*/
		void setTextColor(const phy::Color3B& color);
		/**
		*	颜色
		*/
		const phy::Color3B& getTextColor() const;
		/**
		*	是否多行显示
		*/
		void setMultiLine(bool bMulti);
		/**
		*	是否多行显示
		*/
		bool isMultiLine() const;
		/**
		*	设置文本水平对齐方式
		*/
		void setTextHorizontalAlignment(sys::HorizontalAlignment alignment);
		/**
		*	获取文本水平对齐方式
		*/
		sys::HorizontalAlignment getTextHorizontalAlignment() const;
		/**
		*	设置文本垂直对齐方式
		*/
		void setTextVerticalAlignment(sys::VerticalAlignment alignment);
		/**
		*	获取文本垂直对齐方式
		*/
		sys::VerticalAlignment getTextVerticalAlignment() const;
	public:
		/**
		*	设置提示文本
		*/
		void setPlaceholderString(const std::string& text);
		/**
		*	提示文本
		*/
		const std::string& getPlaceholderString() const;
		/**
		*	设置占位颜色
		*/
		void setPlaceholderTextColor(const phy::Color3B& color);
		/**
		*	占位颜色
		*/
		const phy::Color3B& getPlaceholderTextColor() const;
	public:
		/**
		*	光标闪烁间隔
		*/
		float getCursorFlashTime() const;
		/**
		*	光标闪烁间隔
		*/
		void setCursorFlashTime(float value);
		/**
		*	光标yanse
		*/
		void setCursorColor(const phy::Color4B& color);
	public:
		// 输出操作处理
		virtual void onInputHand(sys::BoardKey key, sys::ButtonStatus type);
	protected:
		// 回退按钮事件
		virtual void onInputKeyBackHandler();
		// 回车按钮事件
		virtual void onInputKeyReturnHandler();
		// 输入字符事件
		virtual void onInputKeyCharHandler(char value);
	protected:
		/**
		*	显示光标
		*/
		void showCursor();
		/**
		*	隐藏光标
		*/
		void hideCursor();
	private:
		// 文本控件
		CtrlText* _ctrlText = nullptr;
		// 提示文本控件
		CtrlText* _ctrlTextPlaceholder = nullptr;
		// 光标
		CtrlImage* _ctrlCursor = nullptr;
		// 是否多行
		bool _multiLine = false;
		// 光标闪烁间隔
		float _cursorFlashTime = 0.25f;
	};
}