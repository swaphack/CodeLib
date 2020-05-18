#pragma once

#include "DrawNode.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// opengl������ͼ�ڵ�
	class PrimitiveNode : public DrawNode
	{
	public:
		PrimitiveNode();
		virtual ~PrimitiveNode();
	public:
		virtual bool init();
	protected:
		virtual void onDraw();
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

		void setColor(const sys::Color4F& color);
		const sys::Color4F& getColor() const;
	private:
		// ���
		float _width = 1;
		// ģʽ
		ShapeMode _drawMode = ShapeMode::POINTS;
		// ������
		std::vector<math::Vector3> _points;

		sys::Color4F _color;
	};
}