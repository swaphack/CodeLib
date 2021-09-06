#pragma once

#include "physicslib.h"
#include "Common/struct/vertex_common.h"

namespace render
{
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
	public:
		/**
		*	���Ӷ���
		*/
		void getBoxPoints(std::vector<math::TrianglePoints>& vecPoints) const;
	protected:
		// �Ƿ���ʾ��
		bool _bBoxVisible = false;
		// ��ɫ
		phy::Color4B _boxColor = phy::Color4B(255, 255, 255, 255);
		// ���
		float _boxLineWidth = 1;
		// ������
		std::vector<math::TrianglePoints> _boxPoints;
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
	protected:
		// ���ؾ��ο�
		math::CubePoints _boxVertex;
	};
}