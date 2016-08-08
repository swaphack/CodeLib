#pragma once

#include "macros.h"

namespace ui
{
	// ui �ؼ���ʾ����
	class UIBoxProtocol
	{
	public:
		UIBoxProtocol();
		virtual ~UIBoxProtocol();
	public:
		// ���þ��ο��Ƿ�ɼ�
		void setBoxVisible(bool status);
		// ���ο��Ƿ�ɼ�
		bool isBoxVisible();
		// ���þ��ο���ʾ��ɫ
		void setBoxColor(const sys::Color4B& color);
		// ��ȡ���ο���ʾ��ɫ
		const sys::Color4B& getBoxColor();
	private:
		// ���ο���ɫ
		sys::Color4B _rectColor;
		// �Ƿ���ʾ���ο�
		bool _bBoxVisible;
	};
}