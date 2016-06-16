#pragma once

#include "CtrlEditBox.h"
#include "CtrlText.h"

namespace render
{
	// 可编辑文本
	class CtrlEditLabel : public CtrlEditBox, public TextProtocol
	{
	public:
		CtrlEditLabel();
		virtual ~CtrlEditLabel();
	public:
		// 设置文本
		virtual void setString(const char* text);
		// 获取显示文本控件
		CtrlText* getCtrlText();
		// 输出操作处理
		virtual void onInputHand(sys::BoardKey key, sys::ButtonStatus type);
	protected:
	private:
		CtrlText* _ctrlText;
	};
}