#pragma once

#include "physicslib.h"

namespace render
{
	class DrawBoxProtocol
	{
	public:
		DrawBoxProtocol();
		virtual ~DrawBoxProtocol();
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
		float getBoxWidth() const;
		/**
		*	矩形框宽度
		*/
		void setBoxWidth(float width);
	protected:
		// 是否显示矩形框
		bool _bBoxVisible = false;
		// 矩形框颜色
		phy::Color4B _boxColor = phy::Color4B(255, 255, 255, 255);
		// 矩形框宽度
		float _boxWidth = 1;
	};
}