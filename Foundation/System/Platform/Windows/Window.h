#pragma once

#include "Platform/macros.h"

#include <windows.h>

namespace sys
{
	// windows ����
	class Window : public WindowImpl
	{
	public:
		Window();
		virtual ~Window();
	public:
		virtual void initWindow(const std::string& title, int32_t width, int32_t height);
	public:
		// ���ھ��
		inline HWND getWnd() { return _wnd; }
		// ����λ��x
		virtual float getPositionX() { return _posX; }
		// ����λ��y
		virtual float getPositionY() { return _posY; }
		// ���ڿ��
		virtual float getWidth() { return _width; }
		// ���ڸ߶�
		virtual float getHeight() { return _height;  }
		// ����
		virtual std::string getTitle() { return _title.c_str(); }
		// �����źŵĴ���
		virtual bool onRecvSignal(Signal* signal);
	public:// ����
		// ����
		virtual Keyboard* getKeyboard();
		// ���
		virtual Mouse* getMouse();
	protected:
		// ��ʼ������
		virtual bool init();
		// ���ٴ���
		virtual bool dispose();
		// ��������
		virtual void listen();
		// ������յ�����Ϣ
		virtual bool onHandSignal(Signal* signal);
	protected:
		// ���ھ��
		HWND _wnd;
		// ����ʵ��
		HINSTANCE _instance;
		// ���ڿ��
		float _width;
		// ���ڸ߶�
		float _height;
		// ����x��λ��
		float _posX;
		// ����y��λ��
		float _posY;
		// ���ڱ���
		std::string _title;
	protected:
		Keyboard* _keyboard;
		Mouse* _mouse;
	};

}