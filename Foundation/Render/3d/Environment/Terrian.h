#pragma once


#include "Common/DrawNode/DrawNode3D.h"

namespace render
{
	/**
	*	地形
	*/
	class Terrian : public DrawNode3D
	{
	public:
		Terrian();
		virtual ~Terrian();
	public:
		virtual bool init();
	public:
		/**
		*	设置地形面积
		*/
		void setTerrianSize(float width, float height);
		/**
		*	设置地形宽度
		*/
		void setTerrianWidth(float width);
		/**
		*	获取地形宽度
		*/
		float getTerrianWidth() const;
		/**
		*	设置地形长度
		*/
		void setTerrianLength(float length);
		/**
		*	获取地形长度
		*/
		float getTerrianLength() const;
		/**
		*	设置地形高度
		*/
		void setTerrianHeight(float minHeight, float maxHeight);
		/**
		*	设置分化次数
		*/
		void setFractalCount(int count);
		/**
		*	获取分化次数
		*/
		int getFractalCount() const;
	protected:
		void onTerrianChange();
	protected:
		math::Size _terrianSize;
		math::FloatInterval _terrianHeight;
		int _fractalCount = 1;
	};
}