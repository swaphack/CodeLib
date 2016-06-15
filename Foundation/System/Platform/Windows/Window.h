#pragma once

#include "../macros.h"
#include <string>
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
		virtual void initWindow(const char* title, int width, int height);
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
		virtual const char* getTitle() { return _title.c_str(); }
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
		// �������ǵĴ��ھ��
		HWND _wnd;
		// ��������ʵ��
		HINSTANCE _instance;
		float _width;
		float _height;
		float _posX;
		float _posY;
		std::string _title;
	protected:
		Keyboard* _keyboard;
		Mouse* _mouse;
	};

}