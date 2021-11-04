#pragma once

#include <map>
#include "mathlib.h"

namespace render
{
	class Box2DProtocol;
	/**
	*	可见的2d盒子
	*/
	class Box2DSpace
	{
	public:
		Box2DSpace();
		virtual ~Box2DSpace();
	public:
		/**
		*	初始化盒子范围
		*/
		void init(const math::Vector2& pos, const math::Size& size);
	public:
		/**
		*	最小矩形大小
		*/
		void setMinBoxSize(int width, int height);
	public:
		/**
		*	添加
		*/
		void addBox(Box2DProtocol* box);
		/**
		*	移除
		*/
		void removeBox(Box2DProtocol* box);
		/**
		*	移除
		*/
		void removeBox(int boxID);
		/**
		*	包含
		*/
		bool containBox(int boxID);
		/**
		*	移除所有盒子
		*/
		void removeAllBoxes();
	public:
		/**
		*	是否包含点击点
		*/
		bool containsTouchPoint(Box2DProtocol* boxProtocol, const math::Vector2& touchPoint);
		/**
		*	包含共享点的盒子信息
		*/
		bool getBoxesOfIncludedPoint(int nID, const math::Vector3& worldPoint, std::map<int, render::Box2DProtocol*>& boxes);
	private:
		// 盒子
		std::map<int, Box2DProtocol*> _boxes;
		// 矩形
		math::Rect _rootRect;
		// 最小矩形大小
		int _minRectWidth = 20;
		int _minRectHeight = 20;
	};
}
