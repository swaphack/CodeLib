#pragma once

#include "../Common/import.h"

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
		// ģʽ
		void setDrawMode(int mode);
		int getDrawMode();
		// ���һ��������
		void appendPoint(const sys::Vector& point);
		// �Ƴ����е�����
		void removeAllPoints();
	protected:
		// ���¼������
		virtual void initSelf();
	private:
		// ���
		float _width;
		// ģʽ
		int _drawMode;
		// ������
		std::vector<sys::Vector> _points;
	};
}