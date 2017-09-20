#pragma once

#include "../Node/ColorNode.h"

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
		void setDrawMode(BeginMode mode);
		int getDrawMode();
		// ���һ��������
		void appendPoint(const sys::Vector3& point);
		// �Ƴ����е�����
		void removeAllPoints();
	protected:
		// ���¼������
		virtual void initSelf();
	private:
		// ���
		float _width;
		// ģʽ
		BeginMode _drawMode;
		// ������
		std::vector<sys::Vector3> _points;
	};
}