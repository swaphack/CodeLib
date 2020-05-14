#pragma once

#include "CtrlEditBox.h"
#include "TextProtocol.h"

namespace render
{
	class CtrlText;

	// 可编辑文本
	class CtrlEditLabel : public CtrlEditBox, public TextProtocol
	{
	public:
		CtrlEditLabel();
		virtual ~CtrlEditLabel();
	public:
		// 设置文本
		void setString(const std::string& text);
		// 获取显示文本控件
		CtrlText* getCtrlText();
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
		CtrlText* _ctrlText = nullptr;
	};
}