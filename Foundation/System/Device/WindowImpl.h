#pragma once

#include "Signal.h"


namespace sys
{
	class WindowImpl
	{
	public:
		virtual ~WindowImpl(){};
	public:
		// ����λ��x
		virtual float getPositionX() = 0;
		// ����λ��y
		virtual float getPositionY() = 0;
		// ���ڿ��
		virtual float getWidth() = 0;
		// ���ڸ߶�
		virtual float getHeight() = 0;
		// ����
		virtual const char* getTitle() = 0;
		// �����źŵĴ���
		virtual bool onRecvSignal(Signal* signal) = 0;
	};
}