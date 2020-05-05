#pragma once

#include "system.h"
#include "CtrlWidget.h"

namespace render
{
	// �༭����״̬
	enum EditInputStatus
	{
		EEIS_BEGIN,	// ��ʼ����
		EEIS_END,	// �������
	};
	typedef void(*EDITINPUT_DELEGATE_HANDLER)(sys::Object* object, EditInputStatus status);

	#define EDITINPUT_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<EDITINPUT_DELEGATE_HANDLER>(&HANDLER_SEL)

	// �༭��
	class CtrlEditBox : public CtrlWidget
	{
	public:
		CtrlEditBox();
		virtual ~CtrlEditBox();
	public:
		// ���ü����Ƿ���Ӧ
		void setKeyboardEnable(bool status);
		// ��ȡ������Ӧ״̬
		bool isKeyboardEnable();
		// ������������¼�
		void setInputListen(EDITINPUT_DELEGATE_HANDLER handler);
		// �����������
		virtual void onInputHand(sys::BoardKey key, sys::ButtonStatus type) {}
	protected:
		// �ɷ��������
		void dispatchInputListen(EditInputStatus status);
		// ��Ӽ��̼���ί��
		void addKeyboardDelegate();
		// �Ƴ����̼���ί��
		void removeKeyboardDelegate();
	protected:
		void onTouchUp(sys::Object* object, float x, float y);
		void onKeyBoardInput(sys::Object* object, sys::BoardKey key, sys::ButtonStatus type);
	private:
		// �����Ƿ����
		bool _keyboardEnabled = false;
		// �༭����ռ����
		EDITINPUT_DELEGATE_HANDLER _editInputHandler;
	};
}