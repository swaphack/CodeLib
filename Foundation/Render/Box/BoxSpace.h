#pragma once

#include "system.h"
#include "mathlib.h"

namespace render
{
	class BoxProtocol;
	class Box2DProtocol;
	class Box3DProtocol;
	class BoxDraw;
	class Box2DSpace;
	class Box3DSpace;

	/**
	*	包围盒空间
	*/
	class BoxSpace : public sys::Object
	{
	public:
		BoxSpace();
		virtual ~BoxSpace();
	public:
		/**
		*	盒子绘制节点
		*/
		void setBoxDraw(BoxDraw* boxDraw);
		/**
		*	盒子绘制节点
		*/
		BoxDraw* getBoxDraw();
	public:
		/**
		*	2d划分的矩形大小
		*/
		void setMinBox2DSize(int width, int height);
		/**
		*	3d划分的矩形大小
		*/
		void setMinBox3DSize(int width, int height, int depth);
	public:
		/**
		*	获取增长的盒子编号
		*/
		int getBoxIncreaseID();
	public:
		/**
		*	添加
		*/
		void addBox(BoxProtocol* box);
		/**
		*	更新盒子
		*/
		void updateBox(BoxProtocol* box);
		/**
		*	移除
		*/
		void removeBox(BoxProtocol* box);
		/**
		*	移除所有盒子
		*/
		void removeAllBoxes();
		/**
		*	获取所有盒子
		*/
		const std::map<int, BoxProtocol*>& getAllBoxes() const;
	public:
		/**
		*	包含触摸点
		*/
		bool containsTouchPoint(const math::Vector2& touchPoint, std::vector<BoxProtocol*>& boxes);
		/**
		*	包含共享点的盒子信息
		*/
		bool getBoxesOfIncludedPoint(const math::Vector3& worldPoint, std::vector<BoxProtocol*>& boxes);
		/**
		*	是否包含点击点
		*/
		bool containsTouchPoint2D(Box2DProtocol* boxProtocol, const math::Vector2& touchPoint);
		/**
		*	包含共享点的盒子信息
		*/
		bool containsTouchPoint3D(Box3DProtocol* boxProtocol, const math::Vector2& touchPoint);
	protected:
		/**
		*	注册事件
		*/
		void registerBoxEvent(BoxProtocol* box);
		/**
		*	移除事件
		*/
		void unregisterBoxEvent(BoxProtocol* box);
		/**
		*	获取键值
		*/
		std::string getRectKey(const math::Rect& rect);
	private:
		// 盒子
		std::map<int, BoxProtocol*> _boxes;
		// 盒子绘制
		BoxDraw* _boxDraw = nullptr;
		// 盒子编号
		int _increaseBoxID = 0;

		Box2DSpace* _2dSpace;
		Box3DSpace* _3dSpace;
	};

#define G_BOXSPACE sys::Instance<render::BoxSpace>::getInstance()
}