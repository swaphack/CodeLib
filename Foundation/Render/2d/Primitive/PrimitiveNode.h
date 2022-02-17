#pragma once

#include "Common/DrawNode/DrawNode2D.h"
#include "Graphic/GLAPI/macros.h"
#include "physicslib.h"

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
			phy::Color4F color;

			PrimitiveVertex(const math::Vector3& point, const phy::Color4F& color)
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
		/**
		*	����ģʽ
		*/ 
		void setDrawMode(DrawMode mode);
		/**
		*	ģʽ
		*/
		DrawMode getDrawMode();
	public:
		/**
		*	���һ��������
		*/
		void appendPoint(const math::Vector3& point);
		/**
		*	���һ��������
		*/
		void appendPoint(const math::Vector3& point, const phy::Color4F& color);
		/**
		*	���һЩ����
		*/
		void appendPoint(const PrimitiveVertex& vertex);
		/**
		*	���������
		*/
		void appendPoints(const std::vector<math::Vector3>& points, const phy::Color4F& color);
		/**
		*	���������
		*/
		void appendPoints(int count, const math::Vector3* points, const phy::Color4F& color);
		/**
		*	�Ƴ����е�����
		*/
		void removeAllPoints();
	public:
		/**
		*	���С
		*/
		void setPointSize(float size);
		/**
		*	���С
		*/
		float getPointSize() const;
	protected:
		void onPrimitiveChange();
		/**
		*	��ɫ�ı�
		*/
		virtual void onDrawNode2DColorChange();
		/**
		*	����ı�
		*/
		virtual void onDrawNode2DTextureChange();
	private:
		// ������Ϣ
		std::vector<PrimitiveVertex> _vertexes;
		/**
		*	���С
		*/
		float _pointSize = 1;
	};
}