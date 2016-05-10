#pragma once

#include "../macros.h"
#include <string>
#include <windows.h>

namespace sys
{
	class Window : public WindowImpl
	{
	public:
		Window();
		virtual ~Window();
	public:
		virtual void initWindow(const char* title, int width, int height);
	public:
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
	protected:
		// ��ʼ������
		virtual bool init();
		// ���ٴ���
		virtual bool dispose();
		// ��������
		virtual void listen();
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
	};

}