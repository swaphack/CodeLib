#pragma once

#include "physicslib.h"
#include "Common/struct/vertex_common.h"

namespace render
{
	/**
	*	绘制包围盒
	*/
	class BoxDrawProtocol
	{
	public:
		BoxDrawProtocol();
		virtual ~BoxDrawProtocol();
	public:
		/**
		*	是否显示矩形框
		*/
		void setBoxVisible(bool bVisible);
		/**
		*	是否显示矩形框
		*/
		bool isBoxVisible() const;
		/**
		*	设置矩形框颜色
		*/
		void setBoxColor(const phy::Color4B& color);
		/**
		*	矩形框颜色
		*/
		const phy::Color4B& getBoxColor() const;
		/**
		*	矩形框宽度
		*/
		float getBoxLineWidth() const;
		/**
		*	矩形框宽度
		*/
		void setBoxLineWidth(float width);
	public:
		/**
		*	盒子顶点
		*/
		void getBoxPoints(std::vector<math::TrianglePoints>& vecPoints) const;
	protected:
		// 是否显示框
		bool _bBoxVisible = false;
		// 颜色
		phy::Color4B _boxColor = phy::Color4B(255, 255, 255, 255);
		// 宽度
		float _boxLineWidth = 1;
		// 三角形
		std::vector<math::TrianglePoints> _boxPoints;
	};

	/**
	*	绘制2d包围盒
	*/
	class Box2DDrawProtocol : public BoxDrawProtocol
	{
	public:
		Box2DDrawProtocol();
		virtual ~Box2DDrawProtocol();
	public:
		/**
		*	盒子顶点
		*/
		void setBoxVertices(const render::RectVertex& rectVertex);

		const render::RectVertex& getLocalRectVertex() const;
	protected:
		// 本地矩形框
		render::RectVertex _localRectVertex;
		// 世界矩形框
		render::RectVertex _worldRectVertex;
	};

	/**
	*	绘制3d包围盒
	*/
	class Box3DDrawProtocol : public BoxDrawProtocol
	{
	public:
		Box3DDrawProtocol();
		virtual ~Box3DDrawProtocol();
	public:
		/**
		*	盒子顶点
		*/
		void setBoxVertices(const render::CubeVertex& cubeVertex);
	protected:
		// 本地矩形框
		math::CubePoints _boxVertex;
	};
}