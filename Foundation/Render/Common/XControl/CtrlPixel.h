#pragma once

#include "../Node/import.h"

namespace render
{
	// 地图
	class CtrlPixel : public Node
	{
	public:
		CtrlPixel();
		virtual ~CtrlPixel();
	public:
		virtual void draw();

		// 获取指定位置的像素
		sys::Color4B getPixel(float x, float y);
		// 获取颜色的像素块
		void getPixelBlock(sys::Point point, sys::Color4B color);
	protected:
		// 重新计算参数
		virtual void initSelf();
	private:
	};
}