#pragma once

#include "../Node/import.h"

namespace render
{
	// opengl基础绘图节点
	class DrawNode : public Node
	{
	public:
		DrawNode();
		virtual ~DrawNode();
	public:
		virtual void draw();
		// 设置颜色
		void setColor(sys::Color4B color);
		sys::Color4B& getColor();
		// 设置宽度
		void setWidth(float width);
		float getWidth();
	protected:
		virtual void updateTranform();
		// 重新计算参数
		virtual void initSelf();
	private:
		sys::Color4B _color;
		float _width;
	};
}