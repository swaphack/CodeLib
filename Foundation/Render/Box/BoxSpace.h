#pragma once

#include "system.h"
#include "mathlib.h"

namespace render
{
	class BoxDrawProtocol;
	class BoxDraw;
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
		*	最小矩形大小
		*/
		void setMinRectSize(int width, int height);
	public:
		/**
		*	获取增长的盒子编号
		*/
		int getBoxIncreaseID();
	public:
		/**
		*	添加
		*/
		void addBox(BoxDrawProtocol* box);
		/**
		*	更新盒子
		*/
		void updateBox(BoxDrawProtocol* box);
		/**
		*	移除
		*/
		void removeBox(BoxDrawProtocol* box);
		/**
		*	移除所有盒子
		*/
		void removeAllBoxes();
		/**
		*	获取所有盒子
		*/
		const std::map<int, BoxDrawProtocol*>& getAllBoxes() const;
	public:
		/**
		*	包含触摸点
		*/
		bool containsTouchPoint(const math::Vector2& touchPoint, std::vector<BoxDrawProtocol*>& boxes);
		/**
		*	包含共享点的盒子信息
		*/
		bool getBoxesOfSharedPoint(const math::Vector3& worldPoint, std::vector<BoxDrawProtocol*>& boxes);
	protected:
		/**
		*	注册事件
		*/
		void registerBoxEvent(BoxDrawProtocol* box);
		/**
		*	移除事件
		*/
		void unregisterBoxEvent(BoxDrawProtocol* box);
		/**
		*	获取键值
		*/
		std::string getRectKey(const math::Rect& rect);
	private:
		// 盒子
		std::map<int, BoxDrawProtocol*> _boxes;
		// 盒子绘制
		BoxDraw* _boxDraw = nullptr;
		// 盒子编号
		int _increaseBoxID = 0;
		// 最小矩形大小
		int _minRectWidth = 20;
		int _minRectHeight = 20;
	};

#define G_BOXSPACE sys::Instance<render::BoxSpace>::getInstance()
}