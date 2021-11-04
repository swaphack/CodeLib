#pragma once

#include "physicslib.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	enum class BoxDrawType
	{
		NONE,
		TWO,
		THREE,
	};
	class Node;
	/**
	*	���ư�Χ��
	*/
	class BoxProtocol
	{
	public:
		BoxProtocol();
		virtual ~BoxProtocol();
	public:
		/**
		*	���ӱ��
		*/
		void setBoxID(int id);
		/**
		*	���ӱ��
		*/
		int getBoxID() const;
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
		*	���Ʒ�ʽ2ά��3ά
		*/
		BoxDrawType getBoxDrawType() const;
		/**
		*	�ڵ�
		*/
		render::Node* getBoxNode() const;
	public:
		/**
		*	���Ӷ���
		*/
		void getBoxPoints(std::vector<math::TrianglePoints>& vecPoints) const;
		/**
		*	���Ӷ���
		*/
		const std::vector<math::TrianglePoints>& getBoxPoints() const;
	protected:
		/**
		*	���������ڵ�
		*/
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
		BoxDrawType _boxDrawType = BoxDrawType::NONE;
		// �ڵ�
		render::Node* _boxNode = nullptr;
		// ���ӱ��
		int _boxID = 0;
	};

	/**
	*	����2d��Χ��
	*/
	class Box2DProtocol : public BoxProtocol
	{
	public:
		Box2DProtocol();
		virtual ~Box2DProtocol();
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
		*	��ȡ��Χ��
		*/
		const math::Rect& getBoxRect() const;
		/**
		*	���ð�Χ��
		*/
		void setBoxRect(const math::Rect& rect);
	public:
		/**
		*	�Ƿ�������2d�����ཻ
		*/
		virtual bool isOverlap(const Box2DProtocol* box2d);
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
	};

	/**
	*	����3d��Χ��
	*/
	class Box3DProtocol : public BoxProtocol
	{
	public:
		Box3DProtocol();
		virtual ~Box3DProtocol();
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
		*	��������
		*/
		const render::CubeVertex& getWorldCubeVertex() const;
		/**
		*	��ȡ��Χ��
		*/
		const math::Cuboids& getBoxCuboids() const;
		/**
		*	���ð�Χ��
		*/
		void setBoxCuboids(const math::Cuboids& cuboids);
	public:

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

		// ��������
		math::Polygon _boxPolygon;
		// �����Χ��
		math::Cuboids _boxCuboids;
	};
}