#pragma once

#include "../Node/ColorNode.h"
#include "ext-config.h"

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
		// ���õ�����
		void setPoints(const std::vector<sys::Vector3>& points);
		// ���һ��������
		void appendPoint(const sys::Vector3& point);
		// ���һ��������
		void appendPoint(const sys::Vector2& point);
		// �Ƴ�һ��������
		void removePoint(const sys::Vector3& point);
		// �Ƴ�һ��������
		void removePoint(const sys::Vector2& point);
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