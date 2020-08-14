#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// opengl������ͼ�ڵ�
	class PrimitiveNode : public DrawNode2D
	{
	public:
		PrimitiveNode();
		virtual ~PrimitiveNode();
	public:
		virtual bool init();
	public:
		// ģʽ
		void setDrawMode(DrawMode mode);

		DrawMode getDrawMode();
	public:
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
	public:
		/**
		*	��С
		*/
		void setPointSize(float size);
		/**
		*	��С
		*/
		float getPointSize() const;
	protected:
		void onPrimitiveChange();
	private:
		// ������
		std::vector<math::Vector3> _points;
		/**
		*	��С
		*/
		float _pointSize = 1;
	};
}