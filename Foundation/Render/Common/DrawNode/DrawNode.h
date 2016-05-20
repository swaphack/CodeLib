#pragma once

#include "../Node/import.h"

namespace render
{
	// opengl基础绘图节点
	class DrawNode : public ColorNode
	{
	public:
		DrawNode();
		virtual ~DrawNode();
	public:
		virtual void draw();
		// 设置宽度
		void setWidth(float width);
		float getWidth();
	protected:
		// 重新计算参数
		virtual void initSelf();
	private:
		float _width;
	};
}