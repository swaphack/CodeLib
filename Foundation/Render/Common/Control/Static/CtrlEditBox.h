#pragma once

#include "macros.h"

namespace render
{
	// 编辑输入状态
	enum EditInputStatus
	{
		EEIS_BEGIN,	// 开始输入
		EEIS_END,	// 输入结束
	};
	typedef void(*EDITINPUT_DELEGATE_HANDLER)(sys::Object* object, EditInputStatus status);

	#define EDITINPUT_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<EDITINPUT_DELEGATE_HANDLER>(&HANDLER_SEL)

	// 编辑框
	class CtrlEditBox : public Node
	{
	public:
		CtrlEditBox();
		virtual ~CtrlEditBox();
	public:
		// 设置键盘是否相应
		void setKeyboardEnable(bool status);
		// 获取键盘相应状态
		bool isKeyboardEnable();
		// 设置输入监听事件
		void setInputListen(EDITINPUT_DELEGATE_HANDLER handler);
		// 输出操作处理
		virtual void onInputHand(sys::BoardKey key, sys::ButtonStatus type) {}
	protected:
		// 派发输入监听
		void dispatchInputListen(EditInputStatus status);
		// 添加键盘监听委托
		void addKeyboardDelegate();
		// 移除键盘监听委托
		void removeKeyboardDelegate();
	private:
		// 是否相应键盘
		bool _keyboardEnabled;
		// 编辑输入空间监听
		EDITINPUT_DELEGATE_HANDLER _editInputHandler;
	};
}