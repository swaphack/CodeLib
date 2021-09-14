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
		/**
		*	���Ӷ���
		*/
		void setBoxVertices(const render::RectVertex& rectVertex);

		const render::RectVertex& getLocalRectVertex() const;
	protected:
		// ���ؾ��ο�
		render::RectVertex _localRectVertex;
		// ������ο�
		render::RectVertex _worldRectVertex;
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
		/**
		*	���Ӷ���
		*/
		void setBoxVertices(const render::CubeVertex& cubeVertex);

		const render::CubeVertex& getLocalCubeVertex() const;
	protected:
		// ���ؾ��ο�
		render::CubeVertex _localCubeVertex;
		// ������ο�
		render::CubeVertex _worldCubeVertex;
	};
}