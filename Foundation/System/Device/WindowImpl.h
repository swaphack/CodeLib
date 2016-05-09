#pragma once

#include "Signal.h"
#include ""

namespace sys
{
	class WindowImpl
	{
	public:
		virtual ~WindowImpl() = 0;
	public:
		// ���ô���λ��
		virtual void setPosition(float x, float y) = 0;
		// ���ô��ڴ�С
		virtual void setSize(float width, float height) = 0;
		// ���ñ���
		virtual void setTitle(const char* title) = 0;
		// �����źŵĴ���
		virtual void onRecvSignal(Signal* signal) = 0;
	};
}