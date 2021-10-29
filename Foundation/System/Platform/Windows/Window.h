#pragma once

#include "Platform/macros.h"

#include <windows.h>

namespace sys
{
	// windows ����
	class Window : public WindowImpl, public DeviceImpl
	{
	public:
		Window();
		virtual ~Window();
	public:
		void initWindow(const std::string& title, int32_t width, int32_t height);
	public:
		// ���ھ��
		inline HWND getWnd() { return _wnd; }
		// �����źŵĴ���
		virtual bool onRecvSignal(const Signal* signal);
	protected:
		// ��ʼ������
		virtual bool init();
		// ���ٴ���
		virtual bool dispose();
		// ��������
		virtual void listen();
		// ������յ�����Ϣ
		virtual bool onHandSignal(const Signal* signal);
	protected:
		// ���ھ��
		HWND _wnd;
		// ����ʵ��
		HINSTANCE _instance;
	
	};

}