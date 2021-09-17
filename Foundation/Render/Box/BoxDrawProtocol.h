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
		/**
		*	矩形框宽度
		*/
		BoxDrawType getBoxDrawType() const;
		/**
		*	节点
		*/
		render::Node* getBoxNode() const;
		/**
		*	是否包含点击点
		*/
		virtual bool containsTouchPoint(const math::Vector2& touchPoint);
	public:
		/**
		*	盒子顶点
		*/
		void getBoxPoints(std::vector<math::TrianglePoints>& vecPoints) const;
	protected:
		void setBoxNode(render::Node* node);
	protected:
		// 是否显示框
		bool _bBoxVisible = false;
		// 颜色
		phy::Color4B _boxColor = phy::Color4B(255, 255, 255, 255);
		// 宽度
		float _boxLineWidth = 1;
		// 三角形
		std::vector<math::TrianglePoints> _boxPoints;
		// 盒子渲染类型
		BoxDrawType _boxDrawType = BoxDrawType::THREE;
		// 节点
		render::Node* m_pBoxNode = nullptr;
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
		void initBox2D(render::Node* node);
	public:
		/**
		*	盒子顶点
		*/
		void setBoxVertices(const render::RectVertex& rectVertex);
		/**
		*	本地坐标
		*/
		const render::RectVertex& getLocalRectVertex() const;
		/**
		*	是否包含点击点
		*/
		virtual bool containsTouchPoint(const math::Vector2& touchPoint);
	protected:
		/**
		*	形状改变
		*/
		void onBox2DCubeChange();
		/**
		*	形状改变
		*/
		void onBox2DWorldCubeChange();
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
		void initBox3D(render::Node* node);
	public:
		/**
		*	盒子顶点
		*/
		void setBoxVertices(const render::CubeVertex& cubeVertex);
		/**
		*	本地坐标
		*/
		const render::CubeVertex& getLocalCubeVertex() const;
		/**
		*	是否包含点击点
		*/
		virtual bool containsTouchPoint(const math::Vector2& touchPoint);
	protected:
		/**
		*	形状改变
		*/
		void onBox3DCubeChange();
		/**
		*	形状改变
		*/
		void onBox3DWorldCubeChange();
	protected:
		// 本地矩形框
		render::CubeVertex _localCubeVertex;
		// 世界矩形框
		render::CubeVertex _worldCubeVertex;
	};
}