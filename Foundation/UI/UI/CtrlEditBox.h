#pragma once

#include "system.h"
#include "CtrlWidget.h"

namespace ui
{
	// �༭����״̬
	enum class EditInputStatus
	{
		BEGIN,	// ��ʼ����
		END,	// �������
	};
	typedef void(*EDITINPUT_DELEGATE_HANDLER)(sys::Object* object, EditInputStatus status);

	#define EDITINPUT_DELEGATTE_SELECTOR(HANDLER_SEL) static_cast<EDITINPUT_DELEGATE_HANDLER>(&HANDLER_SEL)

	typedef std::function<void(sys::Object* object, EditInputStatus status)> EditInputFunc;

	// �༭��
	class CtrlEditBox : public CtrlWidget
	{
	public:
		CtrlEditBox();
		virtual ~CtrlEditBox();
	public:
		virtual bool init();
		virtual void draw();
	public:
		// ���ü����Ƿ���Ӧ
		void setKeyboardEnable(bool status);
		// ��ȡ������Ӧ״̬
		bool isKeyboardEnable();
		// ������������¼�
		void setInputListen(EDITINPUT_DELEGATE_HANDLER handler);

		void setInputFunc(const EditInputFunc& func);
		// �����������
		virtual void onInputHand(sys::BoardKey key, sys::ButtonStatus type) {}
	protected:
		// �ɷ��������
		void dispatchInputListen(EditInputStatus status);
		// ���Ӽ��̼���ί��
		void addKeyboardDelegate();
		// �Ƴ����̼���ί��
		void removeKeyboardDelegate();
	protected:
		void onKeyBoardInput(Node* node, sys::BoardKey key, sys::ButtonStatus type);
	private:
		// �����Ƿ����
		bool _keyboardEnabled = false;
		// �༭����ռ����
		EDITINPUT_DELEGATE_HANDLER _editInputHandler;

		EditInputFunc _editInputFunc = nullptr;
	};
}