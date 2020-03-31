#pragma once

#include "Common/Node/ColorNode.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// opengl������ͼ�ڵ�
	class DrawNode : public ColorNode
	{
	public:
		DrawNode();
		virtual ~DrawNode();
	protected:
		virtual void drawSample();
	public:
		// ���ÿ��
		void setWidth(float width);
		float getWidth();
		// ģʽ
		void setDrawMode(ShapeMode mode);
		ShapeMode getDrawMode();
		// ���õ�����
		void setPoints(const std::vector<math::Vector3>& points);
		// ���һ��������
		void appendPoint(const math::Vector3& point);
		// ���һ��������
		void appendPoint(const math::Vector2& point);
		// �Ƴ�һ��������
		void removePoint(const math::Vector3& point);
		// �Ƴ�һ��������
		void removePoint(const math::Vector2& point);
		// �Ƴ����е�����
		void removeAllPoints();
	private:
		// ���
		float _width = 1;
		// ģʽ
		ShapeMode _drawMode = ShapeMode::POINTS;
		// ������
		std::vector<math::Vector3> _points;
	};
}