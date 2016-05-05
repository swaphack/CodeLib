#pragma once

#include "../Node/import.h"

namespace render
{
	// ��ͼ
	class CtrlPixel : public Node
	{
	public:
		CtrlPixel();
		virtual ~CtrlPixel();
	public:
		virtual void draw();

		// ��ȡָ��λ�õ�����
		sys::Color4B getPixel(float x, float y);
		// ��ȡ��ɫ�����ؿ�
		void getPixelBlock(sys::Point point, sys::Color4B color);
	protected:
		// ���¼������
		virtual void initSelf();
	private:
	};
}