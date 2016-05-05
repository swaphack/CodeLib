#pragma once

#include "../Node/import.h"

namespace render
{
	// opengl������ͼ�ڵ�
	class DrawNode : public Node
	{
	public:
		DrawNode();
		virtual ~DrawNode();
	public:
		virtual void draw();
		// ������ɫ
		void setColor(sys::Color4B color);
		sys::Color4B& getColor();
		// ���ÿ��
		void setWidth(float width);
		float getWidth();
	protected:
		virtual void updateTranform();
		// ���¼������
		virtual void initSelf();
	private:
		sys::Color4B _color;
		float _width;
	};
}