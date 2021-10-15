#pragma once

#include "physicslib.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	enum class BoxDrawType
	{
		TWO,
		THREE,
	};
	class Node;
	/**
	*	���ư�Χ��
	*/
	class BoxDrawProtocol
	{
	public:
		BoxDrawProtocol();
		virtual ~BoxDrawProtocol();
	public:
		/**
		*	�Ƿ���ʾ���ο�
		*/
		void setBoxVisible(bool bVisible);
		/**
		*	�Ƿ���ʾ���ο�
		*/
		bool isBoxVisible() const;
		/**
		*	���þ��ο���ɫ
		*/
		void setBoxColor(const phy::Color4B& color);
		/**
		*	���ο���ɫ
		*/
		const phy::Color4B& getBoxColor() const;
		/**
		*	���ο���
		*/
		float getBoxLineWidth() const;
		/**
		*	���ο���
		*/
		void setBoxLineWidth(float width);
		/**
		*	���ο���
		*/
		BoxDrawType getBoxDrawType() const;
		/**
		*	�ڵ�
		*/
		render::Node* getBoxNode() const;
		/**
		*	�Ƿ���������
		*/
		virtual bool containsTouchPoint(const math::Vector2& touchPoint);
	public:
		/**
		*	���Ӷ���
		*/
		void getBoxPoints(std::vector<math::TrianglePoints>& vecPoints) const;
	protected:
		void setBoxNode(render::Node* node);
	protected:
		// �Ƿ���ʾ��
		bool _bBoxVisible = false;
		// ��ɫ
		phy::Color4B _boxColor = phy::Color4B(255, 255, 255, 255);
		// ���
		float _boxLineWidth = 1;
		// ������
		std::vector<math::TrianglePoints> _boxPoints;
		// ������Ⱦ����
		BoxDrawType _boxDrawType = BoxDrawType::THREE;
		// �ڵ�
		render::Node* m_pBoxNode = nullptr;
	};

	/**
	*	����2d��Χ��
	*/
	class Box2DDrawProtocol : public BoxDrawProtocol
	{
	public:
		Box2DDrawProtocol();
		virtual ~Box2DDrawProtocol();
	public:
		void initBox2D(render::Node* node);
	public:
		/**
		*	���Ӷ���
		*/
		void setBoxVertices(const render::RectVertex& rectVertex);
		/**
		*	��������
		*/
		const render::RectVertex& getLocalRectVertex() const;
		/**
		*	��������
		*/
		const render::RectVertex& getWorldRectVertex() const;
		/**
		*	�����
		*/
		const math::Polygon& getBoxPolygon() const;
		/**
		*	��Χ��
		*/
		const math::Rect& getBoxRect() const;
		/**
		*	�Ƿ���������
		*/
		virtual bool containsTouchPoint(const math::Vector2& touchPoint);
		/**
		*	�Ƿ�������2d�����ཻ
		*/
		virtual bool isOverlap(const Box2DDrawProtocol* box2d);
		/**
		*	�Ƿ��ڻ�����
		*/
		bool isInCanvas();
	protected:
		/**
		*	��״�ı�
		*/
		void onBox2DCubeChange();
		/**
		*	��״�ı�
		*/
		void onBox2DWorldCubeChange();
	protected:
		// ���ؾ��ο�
		render::RectVertex _localRectVertex;
		// ������ο�
		render::RectVertex _worldRectVertex;

		// ��������
		math::Polygon _boxPolygon;
		// �����Χ��
		math::Rect _boxRect;
		// �ڻ�����
		bool _bInCanvas = true;
	};

	/**
	*	����3d��Χ��
	*/
	class Box3DDrawProtocol : public BoxDrawProtocol
	{
	public:
		Box3DDrawProtocol();
		virtual ~Box3DDrawProtocol();
	public:
		void initBox3D(render::Node* node);
	public:
		/**
		*	���Ӷ���
		*/
		void setBoxVertices(const render::CubeVertex& cubeVertex);
		/**
		*	��������
		*/
		const render::CubeVertex& getLocalCubeVertex() const;
		/**
		*	�Ƿ���������
		*/
		virtual bool containsTouchPoint(const math::Vector2& touchPoint);
	protected:
		/**
		*	��״�ı�
		*/
		void onBox3DCubeChange();
		/**
		*	��״�ı�
		*/
		void onBox3DWorldCubeChange();
	protected:
		// ���ؾ��ο�
		render::CubeVertex _localCubeVertex;
		// ������ο�
		render::CubeVertex _worldCubeVertex;
	};
}