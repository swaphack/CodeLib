#pragma once

#include "CtrlEditBox.h"
#include "TextProtocol.h"

namespace render
{
	class CtrlText;

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
		*	设置提示文本
		*/ 
		void setPlaceholder(const std::string& text);
		/**
		*	提示文本
		*/
		const std::string& getPlaceholder() const;
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
		void setTextColor(const sys::Color3B& color);
		/**
		*	颜色
		*/
		const sys::Color3B& getTextColor() const;
		/**
		*	设置占位颜色
		*/
		void setPlaceholderTextColor(const sys::Color3B& color);
		/**
		*	占位颜色
		*/
		const sys::Color3B& getPlaceholderTextColor() const;
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
	private:
		// 文本控件
		CtrlText* _ctrlText = nullptr;
		// 提示文本控件
		CtrlText* _ctrlTextPlaceholder = nullptr;
	};
}