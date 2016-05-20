#pragma once

#include "../Node/import.h"

namespace render
{
	// opengl������ͼ�ڵ�
	class DrawNode : public ColorNode
	{
	public:
		DrawNode();
		virtual ~DrawNode();
	public:
		virtual void draw();
		// ���ÿ��
		void setWidth(float width);
		float getWidth();
	protected:
		// ���¼������
		virtual void initSelf();
	private:
		float _width;
	};
}