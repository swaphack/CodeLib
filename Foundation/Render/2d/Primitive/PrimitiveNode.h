#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Graphic/GLAPI/macros.h"

namespace render
{
	// opengl������ͼ�ڵ�
	class PrimitiveNode : public DrawNode2D
	{
	private:
		struct PrimitiveVertex
		{
			// ��������
			math::Vector3 point;
			// ������ɫ
			sys::Color4B color;

			PrimitiveVertex(const math::Vector3& point, const sys::Color4B& color)
				:point(point), color(color)
			{

			}
		};
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
		// ���һ��������
		void appendPoint(const math::Vector3& point);

		void appendPoint(const math::Vector3& point, const sys::Color4B& color);

		void appendPoint(const PrimitiveVertex& vertex);
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
		// ������Ϣ
		std::vector<PrimitiveVertex> _vertexes;
		/**
		*	��С
		*/
		float _pointSize = 1;
	};
}